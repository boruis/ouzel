
#include "ouzel_graphics_Texture_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_texture(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::Texture>();

	//Constructor
	metaTable.setConstructors<
		ouzel::graphics::Texture()
	>();

	//PublicFunc
	metaTable.addFunction("getResource", &ouzel::graphics::Texture::getResource);
	metaTable.addFunction("getFilename", &ouzel::graphics::Texture::getFilename);
	metaTable.addFunction("getSize", &ouzel::graphics::Texture::getSize);
	metaTable.addFunction("setSize", &ouzel::graphics::Texture::setSize);
	metaTable.addFunction("setData", &ouzel::graphics::Texture::setData);
	metaTable.addFunction("getFlags", &ouzel::graphics::Texture::getFlags);
	metaTable.addFunction("getMipmaps", &ouzel::graphics::Texture::getMipmaps);
	metaTable.addFunction("getFilter", &ouzel::graphics::Texture::getFilter);
	metaTable.addFunction("setFilter", &ouzel::graphics::Texture::setFilter);
	metaTable.addFunction("getAddressX", &ouzel::graphics::Texture::getAddressX);
	metaTable.addFunction("setAddressX", &ouzel::graphics::Texture::setAddressX);
	metaTable.addFunction("getAddressY", &ouzel::graphics::Texture::getAddressY);
	metaTable.addFunction("setAddressY", &ouzel::graphics::Texture::setAddressY);
	metaTable.addFunction("getMaxAnisotropy", &ouzel::graphics::Texture::getMaxAnisotropy);
	metaTable.addFunction("setMaxAnisotropy", &ouzel::graphics::Texture::setMaxAnisotropy);
	metaTable.addFunction("getSampleCount", &ouzel::graphics::Texture::getSampleCount);
	metaTable.addFunction("getPixelFormat", &ouzel::graphics::Texture::getPixelFormat);
	metaTable.addFunction("getClearColorBuffer", &ouzel::graphics::Texture::getClearColorBuffer);
	metaTable.addFunction("setClearColorBuffer", &ouzel::graphics::Texture::setClearColorBuffer);
	metaTable.addFunction("getClearDepthBuffer", &ouzel::graphics::Texture::getClearDepthBuffer);
	metaTable.addFunction("setClearDepthBuffer", &ouzel::graphics::Texture::setClearDepthBuffer);
	metaTable.addFunction("getClearColor", &ouzel::graphics::Texture::getClearColor);
	metaTable.addFunction("setClearColor", &ouzel::graphics::Texture::setClearColor);
	metaTable.addFunction("getClearDepth", &ouzel::graphics::Texture::getClearDepth);
	metaTable.addFunction("setClearDepth", &ouzel::graphics::Texture::setClearDepth);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::graphics::Texture::*)(const Size2 &newSize, uint32_t newFlags, uint32_t newMipmaps, uint32_t newSampleCount, PixelFormat newPixelFormat)>(&ouzel::graphics::Texture::init);
	auto initPtr2 = static_cast<bool(ouzel::graphics::Texture::*)(const std::string &newFilename, uint32_t newFlags, uint32_t newMipmaps, PixelFormat newPixelFormat)>(&ouzel::graphics::Texture::init);
	auto initPtr3 = static_cast<bool(ouzel::graphics::Texture::*)(const std::vector< uint8_t > &newData, const Size2 &newSize, uint32_t newFlags, uint32_t newMipmaps, PixelFormat newPixelFormat)>(&ouzel::graphics::Texture::init);
	auto initPtr4 = static_cast<bool(ouzel::graphics::Texture::*)(const std::vector< Level > &newLevels, const Size2 &newSize, uint32_t newFlags, PixelFormat newPixelFormat)>(&ouzel::graphics::Texture::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2, initPtr3, initPtr4);


	state["oz"]["Texture"].setClass(metaTable);
}
