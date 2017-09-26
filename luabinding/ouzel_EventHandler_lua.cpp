
#include "ouzel_EventHandler_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_eventhandler(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::EventHandler>();

	//Constructor
	metaTable.setConstructors<
		ouzel::EventHandler(int32_t aPriority)
	>();

	//PublicFunc
	metaTable.addFunction("remove", &ouzel::EventHandler::remove);

	state["oz"]["EventHandler"].setClass(metaTable);
}
