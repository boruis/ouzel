local xml = require("xml")

local MemberFuncItem = {
	FuncName = "",
	Args = "",
	RetType = "",
	IsStatic = false,
	IsConstructor = false,
	IsDeConstructor = false,
	IsOperator = false,
}

local ClassParser = {
	className = "",
	nameSpace = "",
	funList = {},
}

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

function ClassParser:parse(classItem)
	self.className = classItem.Name
	self.baseClassName = self:getClassName()
	self.nameSpace = string.gsub(self.className, "::" .. self.baseClassName, "")

	local data = xml.loadpath(classItem.Refid)

	for i, v in ipairs(data[1]) do
		if v.xml == "sectiondef" then

			-- public-static-attrib
			-- public-attrib
			-- public-func
			-- public-static-func
			if v.kind == "public-func" then
				self:parsePublicFuncSection(v, false)
			elseif v.kind == "public-static-func" then
				self:parsePublicFuncSection(v, true)
			end
		end
	end

	-- dump(self)
end

function ClassParser:getClassName()
	local laste = 0
	local s, e = string.find(self.className, "::")
	laste = e

	while true do
		if s ~= nil and e ~= nil then
			laste = e
			s, e = string.find(self.className, "::", e + 1)

			if s == nil and e == nil then
				break
			end
		end
	end

	local baseClsName = string.sub(self.className, laste + 1)

	return baseClsName
end

-- determin the func is constructor or not
function ClassParser:isDeConstructorFunc(funcName)
	local s, e = string.find(funcName, "~")

	if s == nil and e == nil then
		return false
	end

	return true
end

function ClassParser:getFullRetType(t)
	local retStr = ""

	for i, v in ipairs(t) do
		if type(v) == "table" then
			retStr = retStr .. v[1]
		else
			retStr = retStr .. v
		end
	end

	return retStr
end

function ClassParser:filterDefaultArg( argStr )
	local function filterParenthese(str)
		local index = 1
		local start = 0
		local s1, e1

		while true do
			s1, e1 = string.find(str, "%(", start)
			if s1 == nil and e1 == nil then
				break
			end

			-- find first ()
			if index > 1 then
				local s2, e2 = string.find(str, ")", start)

				local tmpStr = string.sub(str, s1, e2)
				tmpStr = string.gsub(tmpStr, "%(", "%%(")
				tmpStr = string.gsub(tmpStr, "%)", "%%)")

				str = string.gsub(str, tmpStr, "")
				start = e2 + 1
			end
				
			start = e1 + 1
			index =  index + 1
		end

		return str
	end

	local function hasDefaultArg()
		local s, e = string.find(argStr, "=")
		if s == nil and e == nil then
			return false
		end
		return true
	end

	if hasDefaultArg() == false then
		return argStr
	end

	-- filter parenthese first
	argStr = filterParenthese(argStr)

	local splited = string.split(argStr, ",")

	local retStr = ""
	for i, v in ipairs(splited) do
		local s1, e1 = string.find(v, "=")
		if s1 ~= nil and e1 ~= nil then
			local e = #v
			local echar = string.sub(v, e, e)
			if echar == ")" then
				e = e - 1
			else
				local s2, e2 = string.find(v, ")", s1)
				if s2 ~= nil then
					e = e2 - 1					
				end
			end

			local sub = string.sub(v, s1, e)
			v = string.gsub(v, sub, "")
		end

		retStr = retStr .. v
		if i ~= #splited then
			retStr = retStr .. ","
		end
	end

	return retStr
end

-- public func
function ClassParser:parsePublicFuncSection(section, isStatic)
	for i, v in ipairs(section) do
		local funcName = ""
		local argString = ""
		local isConstructor = false
		local isDeConstructor = false
		local retType = ""

		-- get func name
		for i, item in ipairs(v) do
			if item.xml == "name" then
				funcName = item[1]
			elseif item.xml == "argsstring" then
				-- 去掉默认值
				argString = self:filterDefaultArg(item[1])
			elseif item.xml == "type" then
				retType = self:getFullRetType(item)
			end
		end

		-- isConstructor?
		if self.baseClassName == funcName then
			isConstructor = true
		end

		if self:isDeConstructorFunc(funcName) then
			isDeConstructor = true
		end

		-- isOperator?
		local isOperator = true

		-- filter operator
		local s, e = string.find(funcName, "operator")
		if s == nil and e == nil then
			isOperator = false
		end

		-- local function fixArgs()
		-- argString = string.gsub(argString, self.baseClassName, self.className)
		
		local tmpItem = {
			FuncName = funcName,
			Args = argString,
			IsStatic = isStatic,
			RetType = retType,
			IsConstructor = isConstructor,
			IsDeConstructor = isDeConstructor,
			IsOperator = isOperator,

		}
		table.insert(self.funList, tmpItem)
	end
end


return ClassParser