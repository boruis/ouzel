
#include "ouzel_Font_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_font(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Font>();

	//PublicFunc
	metaTable.addFunction("getVertices", &ouzel::Font::getVertices);

	state["oz"]["Font"].setClass(metaTable);
}
