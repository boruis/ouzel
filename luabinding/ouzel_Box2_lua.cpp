
#include "ouzel_Box2_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_box2(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Box2>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Box2(),
		ouzel::Box2(const Vector2 &aMin, const Vector2 &aMax),
		ouzel::Box2(const Box2 &box)
	>();

	//PublicFunc
	metaTable.addFunction("getCenter", &ouzel::Box2::getCenter);
	metaTable.addFunction("getCorners", &ouzel::Box2::getCorners);
	metaTable.addFunction("intersects", &ouzel::Box2::intersects);
	metaTable.addFunction("containsPoint", &ouzel::Box2::containsPoint);
	metaTable.addFunction("merge", &ouzel::Box2::merge);
	metaTable.addFunction("set", &ouzel::Box2::set);
	metaTable.addFunction("reset", &ouzel::Box2::reset);
	metaTable.addFunction("isEmpty", &ouzel::Box2::isEmpty);
	metaTable.addFunction("insertPoint", &ouzel::Box2::insertPoint);
	metaTable.addFunction("getSize", &ouzel::Box2::getSize);

	state["oz"]["Box2"].setClass(metaTable);
}
