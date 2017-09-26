
#include "ouzel_graphics_BufferResource_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_bufferresource(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::BufferResource>();

	//PublicFunc
	metaTable.addFunction("setData", &ouzel::graphics::BufferResource::setData);
	metaTable.addFunction("getFlags", &ouzel::graphics::BufferResource::getFlags);
	metaTable.addFunction("getUsage", &ouzel::graphics::BufferResource::getUsage);
	metaTable.addFunction("getSize", &ouzel::graphics::BufferResource::getSize);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::graphics::BufferResource::*)(ouzel::graphics::Buffer::Usage newUsage, uint32_t newFlags, uint32_t newSize)>(&ouzel::graphics::BufferResource::init);
	auto initPtr2 = static_cast<bool(ouzel::graphics::BufferResource::*)(ouzel::graphics::Buffer::Usage newUsage, const std::vector< uint8_t > &newData, uint32_t newFlags)>(&ouzel::graphics::BufferResource::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2);


	state["oz"]["BufferResource"].setClass(metaTable);
}
