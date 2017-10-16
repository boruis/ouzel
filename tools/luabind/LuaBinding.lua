local LuaBinding = {
	outPath = "",
	headers = {},
	genFuncs = {},
}

local needTemplateClass = {
	Scene = 1,
	Actor = 1,
	SceneManager = 1,
	Animator = 1,
	Input = 1,
	Menu = 1,
}

local function tableMax(t)
	if t == nil then
		return 0
	end

	local count = 0
	for k,v in pairs(t) do
		count = count + 1
	end

	return count
end

--split string
function string.split(str, delimiter)
	if str==nil or str=='' or delimiter==nil then
		return nil
	end
	
    local result = {}
    for match in (str..delimiter):gmatch("(.-)"..delimiter) do
        table.insert(result, match)
    end
    return result
end

function getHeaderFileName(className)
	local tmpClassName = string.gsub(className, "::", "_")
	local outFileName = tmpClassName .. "_lua" .. ".hpp"

	return outFileName
end

function getCppFileName(className)
	local tmpClassName = string.gsub(className, "::", "_")
	local outFileName = tmpClassName .. "_lua" .. ".cpp"

	return outFileName
end

function getBindingFuncName(baseClassName)
	local funcName = "void ouzel_luabinding_vector2(kaguya::State &state);"
	
	local outName = string.gsub(funcName, "vector2", string.lower(baseClassName))
	return outName
end

function getCallFuncName(baseClassName)
	local funcName = "ouzel_luabinding_vector2(state);"
	
	local outName = string.gsub(funcName, "vector2", string.lower(baseClassName))
	return outName
end

function saveToPath(path, outStr)
      local file = io.open(path, "w")
      file:write(outStr)
      file:close()
end

function haveSameFuncName(item, data)
	local count = 0

	local curFuncName = data.FuncName
	for i,v in ipairs(item) do
		if curFuncName == v.FuncName then
			count = count + 1
		end
	end

	return count > 1
end

function hasUniquePtrArgs(str)
	local s, e = string.find(str, "std::unique_ptr")
	if s == nil and e == nil then
		s, e = string.find(str, "&&")
		if s == nil and e == nil then
			return false
		end
	end

	return true
end

function haveConstructorNum(item)
	local count = 0

	for i, v in ipairs(item.funList) do
		if v.IsConstructor == true and hasUniquePtrArgs(v.Args) == false then
			count = count + 1
		end
	end

	return count
end

local function fixArgs(argStr)

	argStr = string.gsub(argStr, "ScaleMode", "Camera::ScaleMode", 1)
	argStr = string.gsub(argStr, "%(Usage", "(ouzel::graphics::Buffer::Usage", 1)
	argStr = string.gsub(argStr, "%(Buffer::Usage", "(ouzel::graphics::Buffer::Usage", 1)
	argStr = string.gsub(argStr, " override", "", 1)
	argStr = string.gsub(argStr, ", Type aType", ", ouzel::scene::Ease::Type aType", 1)
	argStr = string.gsub(argStr, ", Func aFunc", ", ouzel::scene::Ease::Func aFunc", 1)
	argStr = string.gsub(argStr, "Level aLevel", "ouzel::Log::Level aLevel", 1)

	argStr = string.gsub(argStr, "const std::vector< Level > &newLevels", "const std::vector< ouzel::graphics::Texture::Level > &newLevels", 1)

	argStr = string.gsub(argStr, "%(Type aType", "(ouzel::obf::Value::Type aType", 1)

	argStr = string.gsub(argStr, "std::vector< ConstantInfo >", "std::vector< ouzel::graphics::Shader::ConstantInfo >")

	return argStr
end

function LuaBinding:genBinding(data, outPath)
	self.outPath = outPath

	for i, v in ipairs(data) do
		self:genOneBinding(v)
	end
end

-- 
function LuaBinding:genOneBinding(item)
	self:genHeader(item)
	self:genCppFile(item)

	-- call all bind funcs
	self:genCallFiles(item)
end


function LuaBinding:genHeader(item)
	local headerFileName = getHeaderFileName(item.className)
	local funcName = getBindingFuncName(item.baseClassName)
	local callFuncName = getCallFuncName(item.baseClassName)

	table.insert(self.headers, headerFileName)
	table.insert(self.genFuncs, callFuncName)

	local headerFilePath = self.outPath .. headerFileName

	local outStr = "#include \"kaguya/kaguya.hpp\"\n\n"

	outStr = outStr .. "#pragma once\n\n"

	outStr = outStr .. funcName

	saveToPath(headerFilePath, outStr)
end

function LuaBinding:genCppFile(item)
	local headerFileName = getHeaderFileName(item.className)
	local cppFileName = getCppFileName(item.className)
	local constructorNum = haveConstructorNum(item)

	local cppFilePath = self.outPath .. cppFileName

	local isFirstConstructor = true
	local isFirstPublicFunc = true
	local isFirstStaticFunc = true

	local pointerFuncs = {}

	local function getConstructor()
		local tmpStr = "\n\t//Constructor\n"
		tmpStr = tmpStr .. "\tmetaTable.setConstructors<\n"
		local index = 0
		for i, v in ipairs(item.funList) do
			if v.IsConstructor == true and hasUniquePtrArgs(v.Args) == false then
				tmpStr = tmpStr .. "\t\t"
				tmpStr = tmpStr .. item.className .. fixArgs(v.Args)
				index = index + 1

				if index ~= constructorNum then
					tmpStr = tmpStr .. ","
				end

				tmpStr = tmpStr .. "\n"
			end
		end
		tmpStr = tmpStr .. "\t>();\n"

		return tmpStr
	end

	local function genFunctionPointor(item, v, index)
		local fptrStr = ""
		local funcFullName = item.className .. "::" .. v.FuncName
		if v.IsStatic == true then
			fptrStr = "\tauto fptrIndex = static_cast<void(*)func_args>(&ouzel::Vector2::add);\n"
		else
			fptrStr = "\tauto fptrIndex = static_cast<void(ouzel::_className_::*)func_args>(&ouzel::Vector2::add);\n"
		end

		fptrStr = string.gsub(fptrStr, "void", v.RetType)
		fptrStr = string.gsub(fptrStr, "(func_args)", fixArgs(v.Args))
		fptrStr = string.gsub(fptrStr, "ouzel::Vector2::add", funcFullName)
		fptrStr = string.gsub(fptrStr, "ouzel::_className_", item.className)

		-- save temp
		if pointerFuncs[v.FuncName] == nil then
			pointerFuncs[v.FuncName] = {}
		end

		-- filter unique_ptr args
		if hasUniquePtrArgs(fptrStr) == false then
			table.insert(pointerFuncs[v.FuncName], {
				fptrStr = fptrStr,
			})
		end
	end

	local function genFunctionPointorStr()
		-- reorder pointerFuncs
		local orderedData = {}
		local keys = {}
		for i, v in pairs(pointerFuncs) do
			table.insert(keys, i)
		end
		table.sort(keys, function(a,b)
        	return a < b
		end)

		local tmpStr = ""
		tmpStr = tmpStr .. "\n\t//Overloaded funcs\n"
		for _, fname in pairs(keys) do
			local funcs = ""
			for i, v in ipairs(pointerFuncs[fname]) do
				local ptrIndex = fname .. "Ptr" .. i
				local funStr = string.gsub(v.fptrStr, "fptrIndex", ptrIndex)
				tmpStr = tmpStr .. funStr
				funcs = funcs .. ptrIndex
				if i ~= #pointerFuncs[fname] then
					funcs = funcs .. ", "
				end
			end

			-- call func
			local tmpCallStr = "\tmetaTable.addOverloadedFunctions(\"angle\", funcs);\n\n"
			tmpCallStr = string.gsub(tmpCallStr, "angle", fname)
			tmpCallStr = string.gsub(tmpCallStr, "funcs", funcs)
			tmpStr = tmpStr .. tmpCallStr
		end

		return tmpStr
	end

	local function getFuncBody()
		local bodyStr = ""

		-- begin with constructor
		if constructorNum > 0 then
			local constructorStr = getConstructor()
			bodyStr = bodyStr .. constructorStr
		end

		local funcPointerIndex = 0

		for i, v in ipairs(item.funList) do
			local tmpStr = ""

			-- fillter the same func name
			local haveSaveFunc = haveSameFuncName(item.funList, v)

			if haveSaveFunc == true and v.IsConstructor == false and v.IsOperator == false then
				-- use function pointor
				funcPointerIndex = funcPointerIndex + 1
				genFunctionPointor(item, v, funcPointerIndex)
			elseif v.IsConstructor == true then
			elseif v.IsDeConstructor == true then
			elseif v.IsOperator == true then
				-- nothing
			elseif v.IsStatic == false then
				local pubFuncStr = "\tmetaTable.addFunction(\"isOne\", &ouzel::Vector2::isOne);\n"
				pubFuncStr = string.gsub(pubFuncStr, "ouzel::Vector2", item.className)
				pubFuncStr = string.gsub(pubFuncStr, "isOne", v.FuncName)

				if isFirstPublicFunc == true then
					isFirstPublicFunc = false
					tmpStr = "\n\t//PublicFunc\n"
				end
				tmpStr = tmpStr .. pubFuncStr
			elseif v.IsStatic == true then
				local staticFuncStr = "\tmetaTable.addStaticFunction(\"isOne\", &ouzel::Vector2::isOne);\n"
				staticFuncStr = string.gsub(staticFuncStr, "ouzel::Vector2", item.className)
				staticFuncStr = string.gsub(staticFuncStr, "isOne", v.FuncName)

				if isFirstStaticFunc == true then
					isFirstStaticFunc = false
					tmpStr = "\n\t//PublicStaticFunc\n"
				end
				tmpStr = tmpStr .. staticFuncStr
			end

			bodyStr = bodyStr .. tmpStr
		end

		-- overloaded funcs
		if tableMax(pointerFuncs) > 0 then
			bodyStr = bodyStr .. genFunctionPointorStr()
		end

		return bodyStr
	end

	local function getBaseClassStr()
		if #item.baseClass == 0 then
			return ""
		end

		if #item.baseClass == 1 then
			return ", " .. item.baseClass[1]
		end
		
		local str = ", kaguya::MultipleBase<"
		for i, v in ipairs(item.baseClass) do
			str = str .. v

			if i ~= #item.baseClass then
				str = str .. ", "
			end
		end
		str = str .. "> "

		return str
	end

	local function getFuncStr()
		local headerStr = "\nvoid ouzel_luabinding_vector2(kaguya::State &state)"
		local funcBegin = "\tauto metaTable = kaguya::UserdataMetatable<ouzel::Vector2, _baseClass_>();"
		funcBegin = string.gsub(funcBegin, "ouzel::Vector2", item.className)

		-- 继承信息
		local baseClassStr = getBaseClassStr()
		funcBegin = string.gsub(funcBegin, ", _baseClass_", baseClassStr)

		local funcEnd = "\tstate[\"oz\"][\"Vector2\"].setClass(metaTable);"
		funcEnd = string.gsub(funcEnd, "Vector2", item.baseClassName)

		local funStr = string.gsub(headerStr, "vector2", string.lower(item.baseClassName))
		funStr = funStr .. "\n{\n"

		funStr = funStr .. funcBegin
		funStr = funStr .. "\n"

		funStr = funStr .. getFuncBody()

		funStr = funStr .. "\n"
		funStr = funStr .. funcEnd

		funStr = funStr .. "\n}"
		return funStr
	end

	local outStr = "\n"
	outStr = outStr .. "#include \"" .. headerFileName .. "\""
	outStr = outStr .. "\n\n"
	outStr = outStr .. "using namespace ouzel;\n"
	if item.nameSpace ~= "ouzel" then
		outStr = outStr .. "using namespace " .. item.nameSpace .. ";\n"
	end

	if needTemplateClass[item.baseClassName] == 1 then
		-- outStr = outStr .. "\n"
		-- outStr = outStr .. "template <typename T>"
	end

	outStr = outStr .. getFuncStr()
	outStr = outStr .. "\n"

	saveToPath(cppFilePath, outStr)
end

function LuaBinding:genCallFiles(item)
	local headerFileName = self.outPath .. "ouzel_lua.hpp"
	local cppFileName = self.outPath .. "ouzel_lua.cpp"
	-- headerfile
	local headerStr = "#include \"kaguya/kaguya.hpp\"\n\n"
	headerStr = headerStr .. "#pragma once\n\n"
	headerStr = headerStr .. "void ouzel_luabinding_all(kaguya::State &state);\n"

	saveToPath(headerFileName, headerStr)

	-- cppfile
	local cppStr = "#include \"ouzel_lua.hpp\"\n"

	for i,v in ipairs(self.headers) do
		local includeStr = "#include \"kaguya/kaguya.hpp\"\n"
		includeStr = string.gsub(includeStr, "kaguya/kaguya.hpp", v)
		cppStr = cppStr .. includeStr
	end
	cppStr = cppStr .. "\n\n"

	local callBodyStrat = "void ouzel_luabinding_all(kaguya::State &state)\n"
	callBodyStrat = callBodyStrat .. "{\n"

	for i,v in ipairs(self.genFuncs) do
		callBodyStrat = callBodyStrat .. "\t"
		callBodyStrat = callBodyStrat .. v
		callBodyStrat = callBodyStrat .. "\n"
	end

	callBodyStrat = callBodyStrat .. "}\n"

	cppStr = cppStr .. callBodyStrat

	saveToPath(cppFileName, cppStr)
end

return LuaBinding