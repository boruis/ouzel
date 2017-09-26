
#include "ouzel_ConvexVolume_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_convexvolume(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::ConvexVolume>();

	//Constructor
	metaTable.setConstructors<
		ouzel::ConvexVolume(),
		ouzel::ConvexVolume(const std::vector< Plane > &aPlanes)
	>();

	//PublicFunc
	metaTable.addFunction("isPointInside", &ouzel::ConvexVolume::isPointInside);
	metaTable.addFunction("isSphereInside", &ouzel::ConvexVolume::isSphereInside);
	metaTable.addFunction("isBoxInside", &ouzel::ConvexVolume::isBoxInside);

	state["oz"]["ConvexVolume"].setClass(metaTable);
}
