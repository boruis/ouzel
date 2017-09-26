
#include "ouzel_scene_Move_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_move(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Move>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Move(float aLength, const Vector3 &aPosition, bool aRelative)
	>();

	//PublicFunc
	metaTable.addFunction("play", &ouzel::scene::Move::play);

	state["oz"]["Move"].setClass(metaTable);
}
