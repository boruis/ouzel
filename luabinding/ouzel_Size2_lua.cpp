
#include "ouzel_Size2_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_size2(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Size2>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Size2(),
		ouzel::Size2(float w, float h),
		ouzel::Size2(const Vector2 &point),
		ouzel::Size2(const Size3 &s)
	>();

	//PublicFunc
	metaTable.addFunction("isZero", &ouzel::Size2::isZero);
	metaTable.addFunction("isOne", &ouzel::Size2::isOne);
	metaTable.addFunction("area", &ouzel::Size2::area);

	//Overloaded funcs
	auto scalePtr1 = static_cast<void(ouzel::Size2::*)(float scalar)>(&ouzel::Size2::scale);
	auto scalePtr2 = static_cast<void(ouzel::Size2::*)(const Vector2 &scale)>(&ouzel::Size2::scale);
	metaTable.addOverloadedFunctions("scale", scalePtr1, scalePtr2);


	state["oz"]["Size2"].setClass(metaTable);
}
