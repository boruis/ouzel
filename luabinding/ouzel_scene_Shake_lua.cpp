
#include "ouzel_scene_Shake_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_shake(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Shake>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Shake(float aLength, const Vector3 &aDistance, float aTimeScale)
	>();

	//PublicFunc
	metaTable.addFunction("play", &ouzel::scene::Shake::play);

	state["oz"]["Shake"].setClass(metaTable);
}
