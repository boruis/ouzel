
#include "ouzel_gui_Button_lua.hpp"

using namespace ouzel;
using namespace ouzel::gui;

void ouzel_luabinding_button(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::gui::Button, kaguya::MultipleBase<ouzel::gui::Widget, ouzel::scene::Actor, ouzel::scene::ActorContainer, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::gui::Button(),
		ouzel::gui::Button(const std::string &normalImage, const std::string &selectedImage, const std::string &pressedImage, const std::string &disabledImage, const std::string &label, const std::string &font, float fontSize, const Color &aLabelColor, const Color &aLabelSelectedColor, const Color &aLabelPressedColor, const Color &aLabelDisabledColor)
	>();

	//PublicFunc
	metaTable.addFunction("setEnabled", &ouzel::gui::Button::setEnabled);
	metaTable.addFunction("getNormalSprite", &ouzel::gui::Button::getNormalSprite);
	metaTable.addFunction("getSelectedSprite", &ouzel::gui::Button::getSelectedSprite);
	metaTable.addFunction("getPressedSprite", &ouzel::gui::Button::getPressedSprite);
	metaTable.addFunction("getDisabledSprite", &ouzel::gui::Button::getDisabledSprite);
	metaTable.addFunction("getLabelDrawable", &ouzel::gui::Button::getLabelDrawable);

	state["oz"]["Button"].setClass(metaTable);
}
