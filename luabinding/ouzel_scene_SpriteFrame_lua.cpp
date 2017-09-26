
#include "ouzel_scene_SpriteFrame_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_spriteframe(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::SpriteFrame>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::SpriteFrame(const Size2 &textureSize, const Rectangle &frameRectangle, bool rotated, const Size2 &sourceSize, const Vector2 &sourceOffset, const Vector2 &pivot),
		ouzel::scene::SpriteFrame(const std::vector< uint16_t > &indices, const std::vector< graphics::VertexPCT > &vertices, const Rectangle &frameRectangle, const Size2 &sourceSize, const Vector2 &sourceOffset, const Vector2 &pivot)
	>();

	//PublicFunc
	metaTable.addFunction("getRectangle", &ouzel::scene::SpriteFrame::getRectangle);
	metaTable.addFunction("getBoundingBox", &ouzel::scene::SpriteFrame::getBoundingBox);
	metaTable.addFunction("getMeshBuffer", &ouzel::scene::SpriteFrame::getMeshBuffer);

	state["oz"]["SpriteFrame"].setClass(metaTable);
}
