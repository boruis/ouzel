
#include "ouzel_Log_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_log(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Log>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Log(Level aLevel),
		ouzel::Log(const Log &other),
		ouzel::Log(Log &&other)
	>();

	state["oz"]["Log"].setClass(metaTable);
}
