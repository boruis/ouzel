
#include "ouzel_graphics_TextureResource_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_textureresource(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::TextureResource>();

	//PublicFunc
	metaTable.addFunction("setSize", &ouzel::graphics::TextureResource::setSize);
	metaTable.addFunction("getSize", &ouzel::graphics::TextureResource::getSize);
	metaTable.addFunction("setData", &ouzel::graphics::TextureResource::setData);
	metaTable.addFunction("getFlags", &ouzel::graphics::TextureResource::getFlags);
	metaTable.addFunction("getMipmaps", &ouzel::graphics::TextureResource::getMipmaps);
	metaTable.addFunction("getFilter", &ouzel::graphics::TextureResource::getFilter);
	metaTable.addFunction("setFilter", &ouzel::graphics::TextureResource::setFilter);
	metaTable.addFunction("getAddressX", &ouzel::graphics::TextureResource::getAddressX);
	metaTable.addFunction("setAddressX", &ouzel::graphics::TextureResource::setAddressX);
	metaTable.addFunction("getAddressY", &ouzel::graphics::TextureResource::getAddressY);
	metaTable.addFunction("setAddressY", &ouzel::graphics::TextureResource::setAddressY);
	metaTable.addFunction("getMaxAnisotropy", &ouzel::graphics::TextureResource::getMaxAnisotropy);
	metaTable.addFunction("setMaxAnisotropy", &ouzel::graphics::TextureResource::setMaxAnisotropy);
	metaTable.addFunction("getClearColorBuffer", &ouzel::graphics::TextureResource::getClearColorBuffer);
	metaTable.addFunction("setClearColorBuffer", &ouzel::graphics::TextureResource::setClearColorBuffer);
	metaTable.addFunction("getClearDepthBuffer", &ouzel::graphics::TextureResource::getClearDepthBuffer);
	metaTable.addFunction("setClearDepthBuffer", &ouzel::graphics::TextureResource::setClearDepthBuffer);
	metaTable.addFunction("getClearColor", &ouzel::graphics::TextureResource::getClearColor);
	metaTable.addFunction("setClearColor", &ouzel::graphics::TextureResource::setClearColor);
	metaTable.addFunction("getClearDepth", &ouzel::graphics::TextureResource::getClearDepth);
	metaTable.addFunction("setClearDepth", &ouzel::graphics::TextureResource::setClearDepth);
	metaTable.addFunction("getSampleCount", &ouzel::graphics::TextureResource::getSampleCount);
	metaTable.addFunction("getPixelFormat", &ouzel::graphics::TextureResource::getPixelFormat);
	metaTable.addFunction("getFrameBufferClearedFrame", &ouzel::graphics::TextureResource::getFrameBufferClearedFrame);
	metaTable.addFunction("setFrameBufferClearedFrame", &ouzel::graphics::TextureResource::setFrameBufferClearedFrame);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::graphics::TextureResource::*)(const Size2 &newSize, uint32_t newFlags, uint32_t newMipmaps, uint32_t newSampleCount, PixelFormat newPixelFormat)>(&ouzel::graphics::TextureResource::init);
	auto initPtr2 = static_cast<bool(ouzel::graphics::TextureResource::*)(const std::vector< uint8_t > &newData, const Size2 &newSize, uint32_t newFlags, uint32_t newMipmaps, PixelFormat newPixelFormat)>(&ouzel::graphics::TextureResource::init);
	auto initPtr3 = static_cast<bool(ouzel::graphics::TextureResource::*)(const std::vector< Texture::Level > &newLevels, const Size2 &newSize, uint32_t newFlags, PixelFormat newPixelFormat)>(&ouzel::graphics::TextureResource::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2, initPtr3);


	state["oz"]["TextureResource"].setClass(metaTable);
}
