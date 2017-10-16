
#include "ouzel_gui_Menu_lua.hpp"

using namespace ouzel;
using namespace ouzel::gui;

void ouzel_luabinding_menu(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::gui::Menu, kaguya::MultipleBase<ouzel::gui::Widget, ouzel::scene::Actor, ouzel::scene::ActorContainer, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::gui::Menu()
	>();

	//PublicFunc
	metaTable.addFunction("setEnabled", &ouzel::gui::Menu::setEnabled);
	metaTable.addFunction("selectWidget", &ouzel::gui::Menu::selectWidget);
	metaTable.addFunction("selectNextWidget", &ouzel::gui::Menu::selectNextWidget);
	metaTable.addFunction("selectPreviousWidget", &ouzel::gui::Menu::selectPreviousWidget);

	//Overloaded funcs
	auto addWidgetPtr1 = static_cast<void(ouzel::gui::Menu::*)(Widget *widget)>(&ouzel::gui::Menu::addWidget);
	metaTable.addOverloadedFunctions("addWidget", addWidgetPtr1);


	state["oz"]["Menu"].setClass(metaTable);
}
