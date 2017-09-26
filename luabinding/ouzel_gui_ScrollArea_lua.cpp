
#include "ouzel_gui_ScrollArea_lua.hpp"

using namespace ouzel;
using namespace ouzel::gui;

void ouzel_luabinding_scrollarea(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::gui::ScrollArea>();

	//Constructor
	metaTable.setConstructors<
		ouzel::gui::ScrollArea()
	>();

	state["oz"]["ScrollArea"].setClass(metaTable);
}
