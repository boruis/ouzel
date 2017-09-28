
#include "ouzel_input_Input_lua.hpp"

using namespace ouzel;
using namespace ouzel::input;

void ouzel_luabinding_input(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::input::Input>();

	//PublicFunc
	metaTable.addFunction("setCursorVisible", &ouzel::input::Input::setCursorVisible);
	metaTable.addFunction("isCursorVisible", &ouzel::input::Input::isCursorVisible);
	metaTable.addFunction("setCursorLocked", &ouzel::input::Input::setCursorLocked);
	metaTable.addFunction("isCursorLocked", &ouzel::input::Input::isCursorLocked);
	metaTable.addFunction("getCursorPosition", &ouzel::input::Input::getCursorPosition);
	metaTable.addFunction("setCursorPosition", &ouzel::input::Input::setCursorPosition);
	metaTable.addFunction("startGamepadDiscovery", &ouzel::input::Input::startGamepadDiscovery);
	metaTable.addFunction("stopGamepadDiscovery", &ouzel::input::Input::stopGamepadDiscovery);
	metaTable.addFunction("isKeyboardKeyDown", &ouzel::input::Input::isKeyboardKeyDown);
	metaTable.addFunction("isMouseButtonDown", &ouzel::input::Input::isMouseButtonDown);
	metaTable.addFunction("keyPress", &ouzel::input::Input::keyPress);
	metaTable.addFunction("keyRelease", &ouzel::input::Input::keyRelease);
	metaTable.addFunction("mouseButtonPress", &ouzel::input::Input::mouseButtonPress);
	metaTable.addFunction("mouseButtonRelease", &ouzel::input::Input::mouseButtonRelease);
	metaTable.addFunction("mouseMove", &ouzel::input::Input::mouseMove);
	metaTable.addFunction("mouseRelativeMove", &ouzel::input::Input::mouseRelativeMove);
	metaTable.addFunction("mouseScroll", &ouzel::input::Input::mouseScroll);
	metaTable.addFunction("touchBegin", &ouzel::input::Input::touchBegin);
	metaTable.addFunction("touchEnd", &ouzel::input::Input::touchEnd);
	metaTable.addFunction("touchMove", &ouzel::input::Input::touchMove);
	metaTable.addFunction("touchCancel", &ouzel::input::Input::touchCancel);
	metaTable.addFunction("showVirtualKeyboard", &ouzel::input::Input::showVirtualKeyboard);
	metaTable.addFunction("hideVirtualKeyboard", &ouzel::input::Input::hideVirtualKeyboard);

	//Overloaded funcs
	auto setCursorPtr1 = static_cast<void(ouzel::input::Input::*)(Cursor *cursor)>(&ouzel::input::Input::setCursor);
	metaTable.addOverloadedFunctions("setCursor", setCursorPtr1);


	state["oz"]["Input"].setClass(metaTable);
}
