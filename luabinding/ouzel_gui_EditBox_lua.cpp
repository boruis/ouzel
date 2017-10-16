
#include "ouzel_gui_EditBox_lua.hpp"

using namespace ouzel;
using namespace ouzel::gui;

void ouzel_luabinding_editbox(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::gui::EditBox, kaguya::MultipleBase<ouzel::gui::Widget, ouzel::scene::Actor, ouzel::scene::ActorContainer, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::gui::EditBox()
	>();

	//PublicFunc
	metaTable.addFunction("setValue", &ouzel::gui::EditBox::setValue);
	metaTable.addFunction("getValue", &ouzel::gui::EditBox::getValue);

	state["oz"]["EditBox"].setClass(metaTable);
}
