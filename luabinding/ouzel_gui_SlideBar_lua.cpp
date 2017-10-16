
#include "ouzel_gui_SlideBar_lua.hpp"

using namespace ouzel;
using namespace ouzel::gui;

void ouzel_luabinding_slidebar(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::gui::SlideBar, kaguya::MultipleBase<ouzel::gui::Widget, ouzel::scene::Actor, ouzel::scene::ActorContainer, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::gui::SlideBar()
	>();

	state["oz"]["SlideBar"].setClass(metaTable);
}
