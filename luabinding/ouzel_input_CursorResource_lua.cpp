
#include "ouzel_input_CursorResource_lua.hpp"

using namespace ouzel;
using namespace ouzel::input;

void ouzel_luabinding_cursorresource(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::input::CursorResource>();

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::input::CursorResource::*)(SystemCursor newSystemCursor)>(&ouzel::input::CursorResource::init);
	auto initPtr2 = static_cast<bool(ouzel::input::CursorResource::*)(const std::vector< uint8_t > &newData, const Size2 &newSize, graphics::PixelFormat newPixelFormat, const Vector2 &newHotSpot)>(&ouzel::input::CursorResource::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2);


	state["oz"]["CursorResource"].setClass(metaTable);
}
