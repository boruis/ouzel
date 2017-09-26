
#include "ouzel_Size3_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_size3(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Size3>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Size3(),
		ouzel::Size3(float w, float h, float d),
		ouzel::Size3(const Vector3 &point),
		ouzel::Size3(const Size2 &s)
	>();

	//PublicFunc
	metaTable.addFunction("isZero", &ouzel::Size3::isZero);
	metaTable.addFunction("isOne", &ouzel::Size3::isOne);
	metaTable.addFunction("volume", &ouzel::Size3::volume);

	//Overloaded funcs
	auto scalePtr1 = static_cast<void(ouzel::Size3::*)(float scalar)>(&ouzel::Size3::scale);
	auto scalePtr2 = static_cast<void(ouzel::Size3::*)(const Vector3 &scale)>(&ouzel::Size3::scale);
	metaTable.addOverloadedFunctions("scale", scalePtr1, scalePtr2);


	state["oz"]["Size3"].setClass(metaTable);
}
