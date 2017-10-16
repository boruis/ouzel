
#include "ouzel_gui_ComboBox_lua.hpp"

using namespace ouzel;
using namespace ouzel::gui;

void ouzel_luabinding_combobox(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::gui::ComboBox, kaguya::MultipleBase<ouzel::gui::Widget, ouzel::scene::Actor, ouzel::scene::ActorContainer, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::gui::ComboBox()
	>();

	state["oz"]["ComboBox"].setClass(metaTable);
}
