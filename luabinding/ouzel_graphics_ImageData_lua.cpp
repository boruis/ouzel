
#include "ouzel_graphics_ImageData_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_imagedata(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::ImageData>();

	//Constructor
	metaTable.setConstructors<
		ouzel::graphics::ImageData()
	>();

	//PublicFunc
	metaTable.addFunction("getSize", &ouzel::graphics::ImageData::getSize);
	metaTable.addFunction("getData", &ouzel::graphics::ImageData::getData);
	metaTable.addFunction("getPixelFormat", &ouzel::graphics::ImageData::getPixelFormat);

	state["oz"]["ImageData"].setClass(metaTable);
}
