
#include "ouzel_INI_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_ini(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::INI>();

	//Constructor
	metaTable.setConstructors<
		ouzel::INI(),
		ouzel::INI(const std::string &filename),
		ouzel::INI(const std::vector< uint8_t > &data)
	>();

	//PublicFunc
	metaTable.addFunction("save", &ouzel::INI::save);
	metaTable.addFunction("encode", &ouzel::INI::encode);
	metaTable.addFunction("getValue", &ouzel::INI::getValue);
	metaTable.addFunction("setValue", &ouzel::INI::setValue);
	metaTable.addFunction("deleteValue", &ouzel::INI::deleteValue);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::INI::*)(const std::string &filename)>(&ouzel::INI::init);
	auto initPtr2 = static_cast<bool(ouzel::INI::*)(const std::vector< uint8_t > &data)>(&ouzel::INI::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2);


	state["oz"]["INI"].setClass(metaTable);
}
