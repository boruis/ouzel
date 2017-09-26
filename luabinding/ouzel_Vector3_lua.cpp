
#include "ouzel_Vector3_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_vector3(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Vector3>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Vector3(),
		ouzel::Vector3(float aX, float aY, float aZ),
		ouzel::Vector3(const Vector3 &p1, const Vector3 &p2),
		ouzel::Vector3(const Vector3 &copy),
		ouzel::Vector3(const Vector2 &vec),
		ouzel::Vector3(const Vector2 &vec, float aZ),
		ouzel::Vector3(const Vector4 &vec),
		ouzel::Vector3(const Color &color)
	>();

	//PublicFunc
	metaTable.addFunction("isZero", &ouzel::Vector3::isZero);
	metaTable.addFunction("isOne", &ouzel::Vector3::isOne);
	metaTable.addFunction("distance", &ouzel::Vector3::distance);
	metaTable.addFunction("distanceSquared", &ouzel::Vector3::distanceSquared);
	metaTable.addFunction("length", &ouzel::Vector3::length);
	metaTable.addFunction("lengthSquared", &ouzel::Vector3::lengthSquared);
	metaTable.addFunction("negate", &ouzel::Vector3::negate);
	metaTable.addFunction("normalize", &ouzel::Vector3::normalize);
	metaTable.addFunction("smooth", &ouzel::Vector3::smooth);
	metaTable.addFunction("getMin", &ouzel::Vector3::getMin);
	metaTable.addFunction("getMax", &ouzel::Vector3::getMax);

	//PublicStaticFunc
	metaTable.addStaticFunction("angle", &ouzel::Vector3::angle);

	//Overloaded funcs
	auto addPtr1 = static_cast<void(ouzel::Vector3::*)(const Vector3 &vec)>(&ouzel::Vector3::add);
	auto addPtr2 = static_cast<void(*)(const Vector3 &v1, const Vector3 &v2, Vector3 &dst)>(&ouzel::Vector3::add);
	metaTable.addOverloadedFunctions("add", addPtr1, addPtr2);

	auto clampPtr1 = static_cast<void(ouzel::Vector3::*)(const Vector3 &min, const Vector3 &max)>(&ouzel::Vector3::clamp);
	auto clampPtr2 = static_cast<void(*)(const Vector3 &vec, const Vector3 &min, const Vector3 &max, Vector3 &dst)>(&ouzel::Vector3::clamp);
	metaTable.addOverloadedFunctions("clamp", clampPtr1, clampPtr2);

	auto crossPtr1 = static_cast<void(ouzel::Vector3::*)(const Vector3 &vec)>(&ouzel::Vector3::cross);
	auto crossPtr2 = static_cast<void(*)(const Vector3 &v1, const Vector3 &v2, Vector3 &dst)>(&ouzel::Vector3::cross);
	auto crossPtr3 = static_cast<Vector3(*)(const Vector3 &v1, const Vector3 &v2)>(&ouzel::Vector3::cross);
	metaTable.addOverloadedFunctions("cross", crossPtr1, crossPtr2, crossPtr3);

	auto dotPtr1 = static_cast<float(ouzel::Vector3::*)(const Vector3 &vec) const>(&ouzel::Vector3::dot);
	auto dotPtr2 = static_cast<float(*)(const Vector3 &v1, const Vector3 &v2)>(&ouzel::Vector3::dot);
	metaTable.addOverloadedFunctions("dot", dotPtr1, dotPtr2);

	auto scalePtr1 = static_cast<void(ouzel::Vector3::*)(float scalar)>(&ouzel::Vector3::scale);
	auto scalePtr2 = static_cast<void(ouzel::Vector3::*)(const Vector3 &scale)>(&ouzel::Vector3::scale);
	metaTable.addOverloadedFunctions("scale", scalePtr1, scalePtr2);

	auto setPtr1 = static_cast<void(ouzel::Vector3::*)(float newX, float newY, float newZ)>(&ouzel::Vector3::set);
	auto setPtr2 = static_cast<void(ouzel::Vector3::*)(const Vector3 &p1, const Vector3 &p2)>(&ouzel::Vector3::set);
	metaTable.addOverloadedFunctions("set", setPtr1, setPtr2);

	auto subtractPtr1 = static_cast<void(ouzel::Vector3::*)(const Vector3 &vec)>(&ouzel::Vector3::subtract);
	auto subtractPtr2 = static_cast<void(*)(const Vector3 &v1, const Vector3 &v2, Vector3 &dst)>(&ouzel::Vector3::subtract);
	metaTable.addOverloadedFunctions("subtract", subtractPtr1, subtractPtr2);


	state["oz"]["Vector3"].setClass(metaTable);
}
