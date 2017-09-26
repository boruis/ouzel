
#include "ouzel_graphics_RenderDevice_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_renderdevice(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::RenderDevice>();

	//PublicFunc
	metaTable.addFunction("getDriver", &ouzel::graphics::RenderDevice::getDriver);
	metaTable.addFunction("setClearColorBuffer", &ouzel::graphics::RenderDevice::setClearColorBuffer);
	metaTable.addFunction("getClearColorBuffer", &ouzel::graphics::RenderDevice::getClearColorBuffer);
	metaTable.addFunction("setClearDepthBuffer", &ouzel::graphics::RenderDevice::setClearDepthBuffer);
	metaTable.addFunction("getClearDepthBuffer", &ouzel::graphics::RenderDevice::getClearDepthBuffer);
	metaTable.addFunction("setClearColor", &ouzel::graphics::RenderDevice::setClearColor);
	metaTable.addFunction("getClearColor", &ouzel::graphics::RenderDevice::getClearColor);
	metaTable.addFunction("setClearDepth", &ouzel::graphics::RenderDevice::setClearDepth);
	metaTable.addFunction("getClearDepth", &ouzel::graphics::RenderDevice::getClearDepth);
	metaTable.addFunction("process", &ouzel::graphics::RenderDevice::process);
	metaTable.addFunction("getSize", &ouzel::graphics::RenderDevice::getSize);
	metaTable.addFunction("getSampleCount", &ouzel::graphics::RenderDevice::getSampleCount);
	metaTable.addFunction("getTextureFilter", &ouzel::graphics::RenderDevice::getTextureFilter);
	metaTable.addFunction("getMaxAnisotropy", &ouzel::graphics::RenderDevice::getMaxAnisotropy);
	metaTable.addFunction("getSupportedResolutions", &ouzel::graphics::RenderDevice::getSupportedResolutions);
	metaTable.addFunction("getRefillQueue", &ouzel::graphics::RenderDevice::getRefillQueue);
	metaTable.addFunction("addDrawCommand", &ouzel::graphics::RenderDevice::addDrawCommand);
	metaTable.addFunction("flushCommands", &ouzel::graphics::RenderDevice::flushCommands);
	metaTable.addFunction("convertScreenToNormalizedLocation", &ouzel::graphics::RenderDevice::convertScreenToNormalizedLocation);
	metaTable.addFunction("convertNormalizedToScreenLocation", &ouzel::graphics::RenderDevice::convertNormalizedToScreenLocation);
	metaTable.addFunction("getDrawCallCount", &ouzel::graphics::RenderDevice::getDrawCallCount);
	metaTable.addFunction("getAPIMajorVersion", &ouzel::graphics::RenderDevice::getAPIMajorVersion);
	metaTable.addFunction("getAPIMinorVersion", &ouzel::graphics::RenderDevice::getAPIMinorVersion);
	metaTable.addFunction("isNPOTTexturesSupported", &ouzel::graphics::RenderDevice::isNPOTTexturesSupported);
	metaTable.addFunction("isMultisamplingSupported", &ouzel::graphics::RenderDevice::isMultisamplingSupported);
	metaTable.addFunction("isAnisotropicFilteringSupported", &ouzel::graphics::RenderDevice::isAnisotropicFilteringSupported);
	metaTable.addFunction("isRenderTargetsSupported", &ouzel::graphics::RenderDevice::isRenderTargetsSupported);
	metaTable.addFunction("getProjectionTransform", &ouzel::graphics::RenderDevice::getProjectionTransform);
	metaTable.addFunction("getFPS", &ouzel::graphics::RenderDevice::getFPS);
	metaTable.addFunction("getAccumulatedFPS", &ouzel::graphics::RenderDevice::getAccumulatedFPS);
	metaTable.addFunction("executeOnRenderThread", &ouzel::graphics::RenderDevice::executeOnRenderThread);

	state["oz"]["RenderDevice"].setClass(metaTable);
}
