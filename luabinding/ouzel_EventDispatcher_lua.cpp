
#include "ouzel_EventDispatcher_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_eventdispatcher(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::EventDispatcher>();

	//PublicFunc
	metaTable.addFunction("dispatchEvents", &ouzel::EventDispatcher::dispatchEvents);
	metaTable.addFunction("addEventHandler", &ouzel::EventDispatcher::addEventHandler);
	metaTable.addFunction("removeEventHandler", &ouzel::EventDispatcher::removeEventHandler);
	metaTable.addFunction("postEvent", &ouzel::EventDispatcher::postEvent);

	state["oz"]["EventDispatcher"].setClass(metaTable);
}
