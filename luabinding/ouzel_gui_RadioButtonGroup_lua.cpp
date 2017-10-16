
#include "ouzel_gui_RadioButtonGroup_lua.hpp"

using namespace ouzel;
using namespace ouzel::gui;

void ouzel_luabinding_radiobuttongroup(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::gui::RadioButtonGroup, kaguya::MultipleBase<ouzel::gui::Widget, ouzel::scene::Actor, ouzel::scene::ActorContainer, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::gui::RadioButtonGroup()
	>();

	state["oz"]["RadioButtonGroup"].setClass(metaTable);
}
