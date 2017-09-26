
#include "ouzel_graphics_Renderer_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_renderer(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::Renderer>();

	//PublicFunc
	metaTable.addFunction("getDevice", &ouzel::graphics::Renderer::getDevice);
	metaTable.addFunction("executeOnRenderThread", &ouzel::graphics::Renderer::executeOnRenderThread);
	metaTable.addFunction("setClearColorBuffer", &ouzel::graphics::Renderer::setClearColorBuffer);
	metaTable.addFunction("getClearColorBuffer", &ouzel::graphics::Renderer::getClearColorBuffer);
	metaTable.addFunction("setClearDepthBuffer", &ouzel::graphics::Renderer::setClearDepthBuffer);
	metaTable.addFunction("getClearDepthBuffer", &ouzel::graphics::Renderer::getClearDepthBuffer);
	metaTable.addFunction("setClearColor", &ouzel::graphics::Renderer::setClearColor);
	metaTable.addFunction("getClearColor", &ouzel::graphics::Renderer::getClearColor);
	metaTable.addFunction("setClearDepth", &ouzel::graphics::Renderer::setClearDepth);
	metaTable.addFunction("getClearDepth", &ouzel::graphics::Renderer::getClearDepth);
	metaTable.addFunction("getSize", &ouzel::graphics::Renderer::getSize);
	metaTable.addFunction("saveScreenshot", &ouzel::graphics::Renderer::saveScreenshot);
	metaTable.addFunction("addDrawCommand", &ouzel::graphics::Renderer::addDrawCommand);

	//PublicStaticFunc
	metaTable.addStaticFunction("getAvailableRenderDrivers", &ouzel::graphics::Renderer::getAvailableRenderDrivers);

	state["oz"]["Renderer"].setClass(metaTable);
}
