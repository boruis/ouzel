
#include "ouzel_gui_Label_lua.hpp"

using namespace ouzel;
using namespace ouzel::gui;

void ouzel_luabinding_label(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::gui::Label, kaguya::MultipleBase<ouzel::gui::Widget, ouzel::scene::Actor, ouzel::scene::ActorContainer, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::gui::Label(const std::string &aText, const std::string &fontFile, float fontSize, Color color, const Vector2 &textAnchor)
	>();

	//PublicFunc
	metaTable.addFunction("setText", &ouzel::gui::Label::setText);
	metaTable.addFunction("getText", &ouzel::gui::Label::getText);
	metaTable.addFunction("getLabelDrawable", &ouzel::gui::Label::getLabelDrawable);

	state["oz"]["Label"].setClass(metaTable);
}
