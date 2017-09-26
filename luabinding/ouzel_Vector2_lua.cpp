
#include "ouzel_Vector2_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_vector2(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Vector2>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Vector2(),
		ouzel::Vector2(float aX, float aY),
		ouzel::Vector2(const Vector2 &p1, const Vector2 &p2),
		ouzel::Vector2(const Vector2 &copy),
		ouzel::Vector2(const Vector3 &vec),
		ouzel::Vector2(const Vector4 &vec)
	>();

	//PublicFunc
	metaTable.addFunction("isZero", &ouzel::Vector2::isZero);
	metaTable.addFunction("isOne", &ouzel::Vector2::isOne);
	metaTable.addFunction("distance", &ouzel::Vector2::distance);
	metaTable.addFunction("distanceSquared", &ouzel::Vector2::distanceSquared);
	metaTable.addFunction("length", &ouzel::Vector2::length);
	metaTable.addFunction("lengthSquared", &ouzel::Vector2::lengthSquared);
	metaTable.addFunction("negate", &ouzel::Vector2::negate);
	metaTable.addFunction("normalize", &ouzel::Vector2::normalize);
	metaTable.addFunction("smooth", &ouzel::Vector2::smooth);
	metaTable.addFunction("getMin", &ouzel::Vector2::getMin);
	metaTable.addFunction("getMax", &ouzel::Vector2::getMax);
	metaTable.addFunction("getAngle", &ouzel::Vector2::getAngle);

	//PublicStaticFunc
	metaTable.addStaticFunction("angle", &ouzel::Vector2::angle);

	//Overloaded funcs
	auto addPtr1 = static_cast<void(ouzel::Vector2::*)(const Vector2 &vec)>(&ouzel::Vector2::add);
	auto addPtr2 = static_cast<void(*)(const Vector2 &v1, const Vector2 &v2, Vector2 &dst)>(&ouzel::Vector2::add);
	metaTable.addOverloadedFunctions("add", addPtr1, addPtr2);

	auto clampPtr1 = static_cast<void(ouzel::Vector2::*)(const Vector2 &min, const Vector2 &max)>(&ouzel::Vector2::clamp);
	auto clampPtr2 = static_cast<void(*)(const Vector2 &vec, const Vector2 &min, const Vector2 &max, Vector2 &dst)>(&ouzel::Vector2::clamp);
	metaTable.addOverloadedFunctions("clamp", clampPtr1, clampPtr2);

	auto dotPtr1 = static_cast<float(ouzel::Vector2::*)(const Vector2 &vec) const>(&ouzel::Vector2::dot);
	auto dotPtr2 = static_cast<float(*)(const Vector2 &v1, const Vector2 &v2)>(&ouzel::Vector2::dot);
	metaTable.addOverloadedFunctions("dot", dotPtr1, dotPtr2);

	auto rotatePtr1 = static_cast<void(ouzel::Vector2::*)(float angle)>(&ouzel::Vector2::rotate);
	auto rotatePtr2 = static_cast<void(ouzel::Vector2::*)(const Vector2 &point, float angle)>(&ouzel::Vector2::rotate);
	metaTable.addOverloadedFunctions("rotate", rotatePtr1, rotatePtr2);

	auto scalePtr1 = static_cast<void(ouzel::Vector2::*)(float scalar)>(&ouzel::Vector2::scale);
	auto scalePtr2 = static_cast<void(ouzel::Vector2::*)(const Vector2 &scale)>(&ouzel::Vector2::scale);
	metaTable.addOverloadedFunctions("scale", scalePtr1, scalePtr2);

	auto setPtr1 = static_cast<void(ouzel::Vector2::*)(float newX, float newY)>(&ouzel::Vector2::set);
	auto setPtr2 = static_cast<void(ouzel::Vector2::*)(const Vector2 &p1, const Vector2 &p2)>(&ouzel::Vector2::set);
	metaTable.addOverloadedFunctions("set", setPtr1, setPtr2);

	auto subtractPtr1 = static_cast<void(ouzel::Vector2::*)(const Vector2 &vec)>(&ouzel::Vector2::subtract);
	auto subtractPtr2 = static_cast<void(*)(const Vector2 &v1, const Vector2 &v2, Vector2 &dst)>(&ouzel::Vector2::subtract);
	metaTable.addOverloadedFunctions("subtract", subtractPtr1, subtractPtr2);


	state["oz"]["Vector2"].setClass(metaTable);
}
