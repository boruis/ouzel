
#include "ouzel_Language_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_language(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Language>();

	//PublicFunc
	metaTable.addFunction("getString", &ouzel::Language::getString);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::Language::*)(const std::string &filename)>(&ouzel::Language::init);
	auto initPtr2 = static_cast<bool(ouzel::Language::*)(const std::vector< uint8_t > &data)>(&ouzel::Language::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2);


	state["oz"]["Language"].setClass(metaTable);
}
