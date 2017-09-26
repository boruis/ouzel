
#include "ouzel_graphics_ImageDataSTB_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_imagedatastb(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::ImageDataSTB>();

	//PublicFunc
	metaTable.addFunction("writeToFile", &ouzel::graphics::ImageDataSTB::writeToFile);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::graphics::ImageDataSTB::*)(const std::string &newFilename, PixelFormat newPixelFormat)>(&ouzel::graphics::ImageDataSTB::init);
	auto initPtr2 = static_cast<bool(ouzel::graphics::ImageDataSTB::*)(const std::vector< uint8_t > &newData, PixelFormat newPixelFormat)>(&ouzel::graphics::ImageDataSTB::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2);


	state["oz"]["ImageDataSTB"].setClass(metaTable);
}
