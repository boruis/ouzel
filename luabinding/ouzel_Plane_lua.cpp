
#include "ouzel_Plane_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_plane(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Plane>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Plane(),
		ouzel::Plane(float aA, float aB, float aC, float aD)
	>();

	//PublicFunc
	metaTable.addFunction("flip", &ouzel::Plane::flip);
	metaTable.addFunction("dot", &ouzel::Plane::dot);
	metaTable.addFunction("normalize", &ouzel::Plane::normalize);

	state["oz"]["Plane"].setClass(metaTable);
}
