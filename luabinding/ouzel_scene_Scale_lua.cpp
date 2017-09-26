
#include "ouzel_scene_Scale_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_scale(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Scale>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Scale(float aLength, const Vector3 &aScale, bool aRelative)
	>();

	//PublicFunc
	metaTable.addFunction("play", &ouzel::scene::Scale::play);

	state["oz"]["Scale"].setClass(metaTable);
}
