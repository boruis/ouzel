
#include "ouzel_UpdateCallback_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_updatecallback(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::UpdateCallback>();

	//Constructor
	metaTable.setConstructors<
		ouzel::UpdateCallback(int32_t aPriority)
	>();

	//PublicFunc
	metaTable.addFunction("remove", &ouzel::UpdateCallback::remove);

	state["oz"]["UpdateCallback"].setClass(metaTable);
}
