
#include "ouzel_Noncopyable_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_noncopyable(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Noncopyable>();

	state["oz"]["Noncopyable"].setClass(metaTable);
}
