
#include "ouzel_gui_RadioButton_lua.hpp"

using namespace ouzel;
using namespace ouzel::gui;

void ouzel_luabinding_radiobutton(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::gui::RadioButton>();

	//Constructor
	metaTable.setConstructors<
		ouzel::gui::RadioButton()
	>();

	//PublicFunc
	metaTable.addFunction("setEnabled", &ouzel::gui::RadioButton::setEnabled);
	metaTable.addFunction("setChecked", &ouzel::gui::RadioButton::setChecked);
	metaTable.addFunction("isChecked", &ouzel::gui::RadioButton::isChecked);

	state["oz"]["RadioButton"].setClass(metaTable);
}
