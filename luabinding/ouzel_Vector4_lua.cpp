
#include "ouzel_Vector4_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_vector4(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Vector4>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Vector4(),
		ouzel::Vector4(float aX, float aY, float aZ, float aW),
		ouzel::Vector4(const Vector4 &p1, const Vector4 &p2),
		ouzel::Vector4(const Vector4 &copy),
		ouzel::Vector4(const Vector2 &v),
		ouzel::Vector4(const Vector3 &v),
		ouzel::Vector4(const Color &color)
	>();

	//PublicFunc
	metaTable.addFunction("isZero", &ouzel::Vector4::isZero);
	metaTable.addFunction("isOne", &ouzel::Vector4::isOne);
	metaTable.addFunction("distance", &ouzel::Vector4::distance);
	metaTable.addFunction("distanceSquared", &ouzel::Vector4::distanceSquared);
	metaTable.addFunction("length", &ouzel::Vector4::length);
	metaTable.addFunction("lengthSquared", &ouzel::Vector4::lengthSquared);
	metaTable.addFunction("negate", &ouzel::Vector4::negate);
	metaTable.addFunction("normalize", &ouzel::Vector4::normalize);
	metaTable.addFunction("smooth", &ouzel::Vector4::smooth);
	metaTable.addFunction("getMin", &ouzel::Vector4::getMin);
	metaTable.addFunction("getMax", &ouzel::Vector4::getMax);

	//PublicStaticFunc
	metaTable.addStaticFunction("angle", &ouzel::Vector4::angle);

	//Overloaded funcs
	auto addPtr1 = static_cast<void(ouzel::Vector4::*)(const Vector4 &vec)>(&ouzel::Vector4::add);
	auto addPtr2 = static_cast<void(*)(const Vector4 &v1, const Vector4 &v2, Vector4 &dst)>(&ouzel::Vector4::add);
	metaTable.addOverloadedFunctions("add", addPtr1, addPtr2);

	auto clampPtr1 = static_cast<void(ouzel::Vector4::*)(const Vector4 &min, const Vector4 &max)>(&ouzel::Vector4::clamp);
	auto clampPtr2 = static_cast<void(*)(const Vector4 &vec, const Vector4 &min, const Vector4 &max, Vector4 &dst)>(&ouzel::Vector4::clamp);
	metaTable.addOverloadedFunctions("clamp", clampPtr1, clampPtr2);

	auto dotPtr1 = static_cast<float(ouzel::Vector4::*)(const Vector4 &vec) const>(&ouzel::Vector4::dot);
	auto dotPtr2 = static_cast<float(*)(const Vector4 &v1, const Vector4 &v2)>(&ouzel::Vector4::dot);
	metaTable.addOverloadedFunctions("dot", dotPtr1, dotPtr2);

	auto scalePtr1 = static_cast<void(ouzel::Vector4::*)(float scalar)>(&ouzel::Vector4::scale);
	auto scalePtr2 = static_cast<void(ouzel::Vector4::*)(const Vector4 &scale)>(&ouzel::Vector4::scale);
	metaTable.addOverloadedFunctions("scale", scalePtr1, scalePtr2);

	auto setPtr1 = static_cast<void(ouzel::Vector4::*)(float newX, float newY, float newZ, float newW)>(&ouzel::Vector4::set);
	auto setPtr2 = static_cast<void(ouzel::Vector4::*)(const Vector4 &p1, const Vector4 &p2)>(&ouzel::Vector4::set);
	metaTable.addOverloadedFunctions("set", setPtr1, setPtr2);

	auto subtractPtr1 = static_cast<void(ouzel::Vector4::*)(const Vector4 &vec)>(&ouzel::Vector4::subtract);
	auto subtractPtr2 = static_cast<void(*)(const Vector4 &v1, const Vector4 &v2, Vector4 &dst)>(&ouzel::Vector4::subtract);
	metaTable.addOverloadedFunctions("subtract", subtractPtr1, subtractPtr2);


	state["oz"]["Vector4"].setClass(metaTable);
}
