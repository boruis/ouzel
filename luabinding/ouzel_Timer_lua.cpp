
#include "ouzel_Timer_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_timer(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Timer, ouzel::Noncopyable>();

	//PublicFunc
	metaTable.addFunction("update", &ouzel::Timer::update);

	state["oz"]["Timer"].setClass(metaTable);
}
