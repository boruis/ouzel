
#include "ouzel_Rectangle_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_rectangle(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Rectangle>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Rectangle(),
		ouzel::Rectangle(float aWidth, float aHeight),
		ouzel::Rectangle(float aX, float aY, float aWidth, float aHeight),
		ouzel::Rectangle(const Vector2 &aPosition, float aWidth, float aHeight),
		ouzel::Rectangle(const Vector2 &aPosition, const Size2 &aSize),
		ouzel::Rectangle(const Rectangle &copy)
	>();

	//PublicFunc
	metaTable.addFunction("isEmpty", &ouzel::Rectangle::isEmpty);
	metaTable.addFunction("left", &ouzel::Rectangle::left);
	metaTable.addFunction("bottom", &ouzel::Rectangle::bottom);
	metaTable.addFunction("right", &ouzel::Rectangle::right);
	metaTable.addFunction("top", &ouzel::Rectangle::top);
	metaTable.addFunction("bottomLeft", &ouzel::Rectangle::bottomLeft);
	metaTable.addFunction("topRight", &ouzel::Rectangle::topRight);
	metaTable.addFunction("inflate", &ouzel::Rectangle::inflate);

	//PublicStaticFunc
	metaTable.addStaticFunction("intersect", &ouzel::Rectangle::intersect);
	metaTable.addStaticFunction("combine", &ouzel::Rectangle::combine);

	//Overloaded funcs
	auto containsPtr1 = static_cast<bool(ouzel::Rectangle::*)(float aX, float aY, float aWidth, float aHeight) const>(&ouzel::Rectangle::contains);
	auto containsPtr2 = static_cast<bool(ouzel::Rectangle::*)(const Rectangle &r) const>(&ouzel::Rectangle::contains);
	metaTable.addOverloadedFunctions("contains", containsPtr1, containsPtr2);

	auto containsPointPtr1 = static_cast<bool(ouzel::Rectangle::*)(float aX, float aY) const>(&ouzel::Rectangle::containsPoint);
	auto containsPointPtr2 = static_cast<bool(ouzel::Rectangle::*)(const Vector2 &point) const>(&ouzel::Rectangle::containsPoint);
	metaTable.addOverloadedFunctions("containsPoint", containsPointPtr1, containsPointPtr2);

	auto intersectsPtr1 = static_cast<bool(ouzel::Rectangle::*)(float aX, float aY, float aWidth, float aHeight) const>(&ouzel::Rectangle::intersects);
	auto intersectsPtr2 = static_cast<bool(ouzel::Rectangle::*)(const Rectangle &r) const>(&ouzel::Rectangle::intersects);
	metaTable.addOverloadedFunctions("intersects", intersectsPtr1, intersectsPtr2);

	auto setPtr1 = static_cast<void(ouzel::Rectangle::*)(float newX, float newY, float newWidth, float newHeight)>(&ouzel::Rectangle::set);
	auto setPtr2 = static_cast<void(ouzel::Rectangle::*)(const Vector2 &newPosition, float newWidth, float newHeight)>(&ouzel::Rectangle::set);
	metaTable.addOverloadedFunctions("set", setPtr1, setPtr2);

	auto setPositionPtr1 = static_cast<void(ouzel::Rectangle::*)(float newX, float newY)>(&ouzel::Rectangle::setPosition);
	auto setPositionPtr2 = static_cast<void(ouzel::Rectangle::*)(const Vector2 &newPosition)>(&ouzel::Rectangle::setPosition);
	metaTable.addOverloadedFunctions("setPosition", setPositionPtr1, setPositionPtr2);


	state["oz"]["Rectangle"].setClass(metaTable);
}
