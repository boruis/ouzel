local sceneManager = oz.sharedEngine:getSceneManager()

local newScene = oz.Scene.new()

local layer = oz.Layer.new()
newScene:addLayer(layer)

sceneManager:setScene(newScene)

-- add camera
local camera = oz.Camera.new(oz.Size2.new(400, 600), 3)
layer:addChild(camera)
dump(camera)


-- display a sprite
local testActor = oz.Actor.new()
layer:addChild(testActor)


local characterSprite = oz.Sprite.new()
characterSprite:init("run.json", false, 0, 0, oz.Vector2.new(0.5, 0.5))
characterSprite:play(true, 0.1)

testActor:addComponent(characterSprite)
