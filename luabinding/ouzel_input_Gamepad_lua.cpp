
#include "ouzel_input_Gamepad_lua.hpp"

using namespace ouzel;
using namespace ouzel::input;

void ouzel_luabinding_gamepad(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::input::Gamepad>();

	//PublicFunc
	metaTable.addFunction("getName", &ouzel::input::Gamepad::getName);
	metaTable.addFunction("getVendorId", &ouzel::input::Gamepad::getVendorId);
	metaTable.addFunction("getProductId", &ouzel::input::Gamepad::getProductId);
	metaTable.addFunction("isAttached", &ouzel::input::Gamepad::isAttached);
	metaTable.addFunction("setAbsoluteDpadValues", &ouzel::input::Gamepad::setAbsoluteDpadValues);
	metaTable.addFunction("isAbsoluteDpadValues", &ouzel::input::Gamepad::isAbsoluteDpadValues);
	metaTable.addFunction("getPlayerIndex", &ouzel::input::Gamepad::getPlayerIndex);
	metaTable.addFunction("setPlayerIndex", &ouzel::input::Gamepad::setPlayerIndex);
	metaTable.addFunction("getButtonState", &ouzel::input::Gamepad::getButtonState);
	metaTable.addFunction("setVibration", &ouzel::input::Gamepad::setVibration);
	metaTable.addFunction("getVibration", &ouzel::input::Gamepad::getVibration);

	state["oz"]["Gamepad"].setClass(metaTable);
}
