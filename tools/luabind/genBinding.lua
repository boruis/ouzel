require("dump")

local classLoader = require("Parser")
local binding = require("LuaBinding")

local outputPath = "../../luabinding/"

classLoader:load("../../build/xml/", "index.xml")

local parseData = classLoader:parse()

-- gen binding
binding:genBinding(parseData, outputPath)

-- dump(parseData, "", 8)