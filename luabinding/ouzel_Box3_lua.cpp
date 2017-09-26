
#include "ouzel_Box3_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_box3(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Box3>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Box3(),
		ouzel::Box3(const Vector3 &aMin, const Vector3 &aMax),
		ouzel::Box3(const Box3 &box),
		ouzel::Box3(const Box2 &box)
	>();

	//PublicFunc
	metaTable.addFunction("getCenter", &ouzel::Box3::getCenter);
	metaTable.addFunction("getCorners", &ouzel::Box3::getCorners);
	metaTable.addFunction("intersects", &ouzel::Box3::intersects);
	metaTable.addFunction("containsPoint", &ouzel::Box3::containsPoint);
	metaTable.addFunction("merge", &ouzel::Box3::merge);
	metaTable.addFunction("set", &ouzel::Box3::set);
	metaTable.addFunction("reset", &ouzel::Box3::reset);
	metaTable.addFunction("isEmpty", &ouzel::Box3::isEmpty);
	metaTable.addFunction("insertPoint", &ouzel::Box3::insertPoint);
	metaTable.addFunction("getSize", &ouzel::Box3::getSize);

	state["oz"]["Box3"].setClass(metaTable);
}
