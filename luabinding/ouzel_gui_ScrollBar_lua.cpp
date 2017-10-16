
#include "ouzel_gui_ScrollBar_lua.hpp"

using namespace ouzel;
using namespace ouzel::gui;

void ouzel_luabinding_scrollbar(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::gui::ScrollBar, kaguya::MultipleBase<ouzel::gui::Widget, ouzel::scene::Actor, ouzel::scene::ActorContainer, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::gui::ScrollBar()
	>();

	state["oz"]["ScrollBar"].setClass(metaTable);
}
