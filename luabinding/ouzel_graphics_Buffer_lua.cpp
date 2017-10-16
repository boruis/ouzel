
#include "ouzel_graphics_Buffer_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_buffer(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::Buffer, ouzel::Noncopyable>();

	//Constructor
	metaTable.setConstructors<
		ouzel::graphics::Buffer()
	>();

	//PublicFunc
	metaTable.addFunction("getResource", &ouzel::graphics::Buffer::getResource);
	metaTable.addFunction("getFlags", &ouzel::graphics::Buffer::getFlags);
	metaTable.addFunction("getUsage", &ouzel::graphics::Buffer::getUsage);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::graphics::Buffer::*)(ouzel::graphics::Buffer::Usage newUsage, uint32_t newFlags, uint32_t newSize)>(&ouzel::graphics::Buffer::init);
	auto initPtr2 = static_cast<bool(ouzel::graphics::Buffer::*)(ouzel::graphics::Buffer::Usage newUsage, const void *newData, uint32_t newSize, uint32_t newFlags)>(&ouzel::graphics::Buffer::init);
	auto initPtr3 = static_cast<bool(ouzel::graphics::Buffer::*)(ouzel::graphics::Buffer::Usage newUsage, const std::vector< uint8_t > &newData, uint32_t newFlags)>(&ouzel::graphics::Buffer::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2, initPtr3);

	auto setDataPtr1 = static_cast<bool(ouzel::graphics::Buffer::*)(const void *newData, uint32_t newSize)>(&ouzel::graphics::Buffer::setData);
	auto setDataPtr2 = static_cast<bool(ouzel::graphics::Buffer::*)(const std::vector< uint8_t > &newData)>(&ouzel::graphics::Buffer::setData);
	metaTable.addOverloadedFunctions("setData", setDataPtr1, setDataPtr2);


	state["oz"]["Buffer"].setClass(metaTable);
}
