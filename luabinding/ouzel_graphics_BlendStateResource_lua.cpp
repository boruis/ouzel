
#include "ouzel_graphics_BlendStateResource_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_blendstateresource(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::BlendStateResource>();

	//PublicFunc
	metaTable.addFunction("init", &ouzel::graphics::BlendStateResource::init);
	metaTable.addFunction("isBlendingEnabled", &ouzel::graphics::BlendStateResource::isBlendingEnabled);
	metaTable.addFunction("getColorBlendSource", &ouzel::graphics::BlendStateResource::getColorBlendSource);
	metaTable.addFunction("getColorBlendDest", &ouzel::graphics::BlendStateResource::getColorBlendDest);
	metaTable.addFunction("getColorOperation", &ouzel::graphics::BlendStateResource::getColorOperation);
	metaTable.addFunction("getAlphaBlendSource", &ouzel::graphics::BlendStateResource::getAlphaBlendSource);
	metaTable.addFunction("getAlphaBlendDest", &ouzel::graphics::BlendStateResource::getAlphaBlendDest);
	metaTable.addFunction("getAlphaOperation", &ouzel::graphics::BlendStateResource::getAlphaOperation);
	metaTable.addFunction("getColorMask", &ouzel::graphics::BlendStateResource::getColorMask);

	state["oz"]["BlendStateResource"].setClass(metaTable);
}
