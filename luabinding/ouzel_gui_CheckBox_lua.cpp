
#include "ouzel_gui_CheckBox_lua.hpp"

using namespace ouzel;
using namespace ouzel::gui;

void ouzel_luabinding_checkbox(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::gui::CheckBox, kaguya::MultipleBase<ouzel::gui::Widget, ouzel::scene::Actor, ouzel::scene::ActorContainer, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::gui::CheckBox(const std::string &normalImage, const std::string &selectedImage, const std::string &pressedImage, const std::string &disabledImage, const std::string &tickImage)
	>();

	//PublicFunc
	metaTable.addFunction("setEnabled", &ouzel::gui::CheckBox::setEnabled);
	metaTable.addFunction("setChecked", &ouzel::gui::CheckBox::setChecked);
	metaTable.addFunction("isChecked", &ouzel::gui::CheckBox::isChecked);
	metaTable.addFunction("getNormalSprite", &ouzel::gui::CheckBox::getNormalSprite);
	metaTable.addFunction("getSelectedSprite", &ouzel::gui::CheckBox::getSelectedSprite);
	metaTable.addFunction("getPressedSprite", &ouzel::gui::CheckBox::getPressedSprite);
	metaTable.addFunction("getDisabledSprite", &ouzel::gui::CheckBox::getDisabledSprite);

	state["oz"]["CheckBox"].setClass(metaTable);
}
