-- get all class list
local xml = require("xml")
local ClassParser = require("ClassParser")

local ClassItem = {
	Name = "",
	Refid = ""
}

local ClassList = {
	classList = {},
}


-- filter
local filterList = {
	-- empty class
	"ouzel::graphics::Renderer",
	"ouzel::graphics::RenderDevice",
	"ouzel::graphics::RenderDeviceEmpty",
	"ouzel::graphics::BufferResourceEmpty",
	"ouzel::graphics::AudioDeviceEmpty",
	"ouzel::graphics::BlendStateResourceEmpty",
	"ouzel::graphics::BufferResourceEmpty",
	"ouzel::graphics::MeshBufferResourceEmpty",
	"ouzel::graphics::RenderDeviceEmpty",
	"ouzel::graphics::ShaderResourceEmpty",
	"ouzel::graphics::TextureResourceEmpty",
	"ouzel::audio::AudioDeviceEmpty",
	-- platform related
	"ouzel::EngineAndroid",
	"ouzel::EngineEm",
	"ouzel::EngineIOS",
	"ouzel::EngineLinux",
	"ouzel::EngineMacOS",
	"ouzel::EngineRasp",
	"ouzel::EngineTVOS",
	"ouzel::EngineWin",

	"ouzel::FileSystemAndroid",
	"ouzel::FileSystemEm",
	"ouzel::FileSystemIOS",
	"ouzel::FileSystemLinux",
	"ouzel::FileSystemMacOS",
	"ouzel::FileSystemRasp",
	"ouzel::FileSystemTVOS",
	"ouzel::FileSystemWin",
	"ouzel::FileSystem",

	"ouzel::WindowAndroid",
	"ouzel::WindowEm",
	"ouzel::WindowIOS",
	"ouzel::WindowLinux",
	"ouzel::WindowMacOS",
	"ouzel::WindowRasp",
	"ouzel::WindowTVOS",
	"ouzel::WindowWin",

	"ouzel::input::CursorResourceLinux",
	"ouzel::input::CursorResourceMacOS",
	"ouzel::input::CursorResourceWin",
	
	"ouzel::input::GamepadAndroid",
	"ouzel::input::GamepadDI",
	"ouzel::input::GamepadEm",
	"ouzel::input::GamepadGC",
	"ouzel::input::GamepadIOKit",
	"ouzel::input::GamepadIOS",
	"ouzel::input::GamepadLinux",
	"ouzel::input::GamepadRasp",
	"ouzel::input::GamepadTVOS",
	"ouzel::input::GamepadXI",

	"ouzel::input::InputAndroid",
	"ouzel::input::InputEm",
	"ouzel::input::InputIOS",
	"ouzel::input::InputLinux",
	"ouzel::input::InputMacOS",
	"ouzel::input::InputRasp",
	"ouzel::input::InputTVOS",
	"ouzel::input::InputWin",
	-- other
	"ouzel::audio::Stream",
	"ouzel::audio::StreamVorbis",
	"ouzel::audio::StreamWave",
	"ouzel::audio::SoundData",
	"ouzel::audio::SoundDataVorbis",
	"ouzel::audio::SoundDataWave",
	"ouzel::Archive",
	"ouzel::TTFont",
	"ouzel::TTFont::CharDescriptor",
	"ouzel::BMFont::CharDescriptor",
	"ouzel::network::Client",

	"ouzel::gui::ScrollArea",
	"ouzel::Language",
}

for i,v in ipairs(filterList) do
	filterList[v] = i
end



-- load xmlfile to get all class info
function ClassList:load(basePath, xmlFile)
	local xmlPath = basePath .. xmlFile

	local data = xml.loadpath(xmlPath)

	for i, v in ipairs(data) do
		if v.kind == "class" then
			local tmpItem = {
				Name = v[1][1],
				BasePath = basePath,
				Refid = basePath .. v.refid .. ".xml"
			}

			table.insert(self.classList, tmpItem)
		else
			-- print(v.kind)
		end
	end
end

function ClassList:isOuzelClass(className)
	local s, e = string.find(className, "ouzel")

	if s == nil and e == nil then
		return false
	end

	return true
end

-- parse class detail
function ClassList:parse()
	local res = {}

	for i, item in ipairs(self.classList) do
		local omit = filterList[item.Name] == nil
		if omit == false then
			print("omiting..." .. item.Name)
		end

		-- only handle class in namespace ouzel
		if self:isOuzelClass(item.Name) == true and filterList[item.Name] == nil then
		-- if item.Name == "ouzel::scene::Camera" then
			local tmpParser = clone(ClassParser)

			tmpParser:parse(item)

			table.insert(res, tmpParser)
		-- end
		end
	end

	return res
end


return ClassList
