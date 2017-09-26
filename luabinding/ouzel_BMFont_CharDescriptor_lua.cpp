
#include "ouzel_BMFont_CharDescriptor_lua.hpp"

using namespace ouzel;
using namespace ouzel::BMFont;

void ouzel_luabinding_chardescriptor(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::BMFont::CharDescriptor>();

	state["oz"]["CharDescriptor"].setClass(metaTable);
}
