
#include "ouzel_graphics_BlendState_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_blendstate(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::BlendState, ouzel::Noncopyable>();

	//Constructor
	metaTable.setConstructors<
		ouzel::graphics::BlendState()
	>();

	//PublicFunc
	metaTable.addFunction("init", &ouzel::graphics::BlendState::init);
	metaTable.addFunction("getResource", &ouzel::graphics::BlendState::getResource);
	metaTable.addFunction("isBlendingEnabled", &ouzel::graphics::BlendState::isBlendingEnabled);
	metaTable.addFunction("getColorBlendSource", &ouzel::graphics::BlendState::getColorBlendSource);
	metaTable.addFunction("getColorBlendDest", &ouzel::graphics::BlendState::getColorBlendDest);
	metaTable.addFunction("getColorOperation", &ouzel::graphics::BlendState::getColorOperation);
	metaTable.addFunction("getAlphaBlendSource", &ouzel::graphics::BlendState::getAlphaBlendSource);
	metaTable.addFunction("getAlphaBlendDest", &ouzel::graphics::BlendState::getAlphaBlendDest);
	metaTable.addFunction("getAlphaOperation", &ouzel::graphics::BlendState::getAlphaOperation);
	metaTable.addFunction("getColorMask", &ouzel::graphics::BlendState::getColorMask);

	state["oz"]["BlendState"].setClass(metaTable);
}
