local newScene = oz.Scene.new()
local sceneManager = oz.sharedEngine:getSceneManager()


local layer = oz.Layer.new()
newScene:addLayer(layer)


sceneManager:setScene(newScene)



local camera = oz.Camera.new(oz.Size2.new(400, 600), 3)
layer:addChild(camera)
dump(camera)
