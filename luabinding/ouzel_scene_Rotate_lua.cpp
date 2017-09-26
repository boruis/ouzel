
#include "ouzel_scene_Rotate_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_rotate(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Rotate>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Rotate(float aLength, const Vector3 &aRotation, bool aRelative)
	>();

	//PublicFunc
	metaTable.addFunction("play", &ouzel::scene::Rotate::play);

	state["oz"]["Rotate"].setClass(metaTable);
}
