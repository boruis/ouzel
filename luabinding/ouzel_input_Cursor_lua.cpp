
#include "ouzel_input_Cursor_lua.hpp"

using namespace ouzel;
using namespace ouzel::input;

void ouzel_luabinding_cursor(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::input::Cursor, ouzel::Noncopyable>();

	//Constructor
	metaTable.setConstructors<
		ouzel::input::Cursor(),
		ouzel::input::Cursor(SystemCursor systemCursor),
		ouzel::input::Cursor(const std::string &filename, const Vector2 &hotSpot)
	>();

	//PublicFunc
	metaTable.addFunction("getResource", &ouzel::input::Cursor::getResource);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::input::Cursor::*)(SystemCursor systemCursor)>(&ouzel::input::Cursor::init);
	auto initPtr2 = static_cast<bool(ouzel::input::Cursor::*)(const std::string &filename, const Vector2 &hotSpot)>(&ouzel::input::Cursor::init);
	auto initPtr3 = static_cast<bool(ouzel::input::Cursor::*)(const std::vector< uint8_t > &data, const Size2 &size, graphics::PixelFormat pixelFormat, const Vector2 &hotSpot)>(&ouzel::input::Cursor::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2, initPtr3);


	state["oz"]["Cursor"].setClass(metaTable);
}
