
#include "ouzel_gui_Widget_lua.hpp"

using namespace ouzel;
using namespace ouzel::gui;

void ouzel_luabinding_widget(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::gui::Widget>();

	//Constructor
	metaTable.setConstructors<
		ouzel::gui::Widget()
	>();

	//PublicFunc
	metaTable.addFunction("getMenu", &ouzel::gui::Widget::getMenu);
	metaTable.addFunction("setEnabled", &ouzel::gui::Widget::setEnabled);
	metaTable.addFunction("isEnabled", &ouzel::gui::Widget::isEnabled);
	metaTable.addFunction("isSelected", &ouzel::gui::Widget::isSelected);

	state["oz"]["Widget"].setClass(metaTable);
}
