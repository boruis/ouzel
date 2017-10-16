
#include "ouzel_scene_Sprite_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_sprite(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Sprite, kaguya::MultipleBase<ouzel::scene::Component, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Sprite(),
		ouzel::scene::Sprite(const SpriteDefinition &spriteDefinition),
		ouzel::scene::Sprite(const std::string &filename, bool mipmaps, uint32_t spritesX, uint32_t spritesY, const Vector2 &pivot),
		ouzel::scene::Sprite(std::shared_ptr< graphics::Texture > texture, uint32_t spritesX, uint32_t spritesY, const Vector2 &pivot)
	>();

	//PublicFunc
	metaTable.addFunction("update", &ouzel::scene::Sprite::update);
	metaTable.addFunction("draw", &ouzel::scene::Sprite::draw);
	metaTable.addFunction("getMaterial", &ouzel::scene::Sprite::getMaterial);
	metaTable.addFunction("setMaterial", &ouzel::scene::Sprite::setMaterial);
	metaTable.addFunction("getSize", &ouzel::scene::Sprite::getSize);
	metaTable.addFunction("getOffset", &ouzel::scene::Sprite::getOffset);
	metaTable.addFunction("setOffset", &ouzel::scene::Sprite::setOffset);
	metaTable.addFunction("play", &ouzel::scene::Sprite::play);
	metaTable.addFunction("stop", &ouzel::scene::Sprite::stop);
	metaTable.addFunction("reset", &ouzel::scene::Sprite::reset);
	metaTable.addFunction("isPlaying", &ouzel::scene::Sprite::isPlaying);
	metaTable.addFunction("getFrames", &ouzel::scene::Sprite::getFrames);
	metaTable.addFunction("setCurrentFrame", &ouzel::scene::Sprite::setCurrentFrame);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::scene::Sprite::*)(const SpriteDefinition &spriteDefinition)>(&ouzel::scene::Sprite::init);
	auto initPtr2 = static_cast<bool(ouzel::scene::Sprite::*)(const std::string &filename, bool mipmaps, uint32_t spritesX, uint32_t spritesY, const Vector2 &pivot)>(&ouzel::scene::Sprite::init);
	auto initPtr3 = static_cast<bool(ouzel::scene::Sprite::*)(std::shared_ptr< graphics::Texture > newTexture, uint32_t spritesX, uint32_t spritesY, const Vector2 &pivot)>(&ouzel::scene::Sprite::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2, initPtr3);


	state["oz"]["Sprite"].setClass(metaTable);
}
