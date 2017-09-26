
#include "ouzel_scene_Fade_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_fade(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Fade>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Fade(float aLength, float aOpacity, bool aRelative)
	>();

	//PublicFunc
	metaTable.addFunction("play", &ouzel::scene::Fade::play);

	state["oz"]["Fade"].setClass(metaTable);
}
