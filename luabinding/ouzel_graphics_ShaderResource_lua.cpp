
#include "ouzel_graphics_ShaderResource_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_shaderresource(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::ShaderResource>();

	//PublicFunc
	metaTable.addFunction("init", &ouzel::graphics::ShaderResource::init);
	metaTable.addFunction("getVertexAttributes", &ouzel::graphics::ShaderResource::getVertexAttributes);
	metaTable.addFunction("getVertexSize", &ouzel::graphics::ShaderResource::getVertexSize);
	metaTable.addFunction("getPixelShaderAlignment", &ouzel::graphics::ShaderResource::getPixelShaderAlignment);
	metaTable.addFunction("getVertexShaderAlignment", &ouzel::graphics::ShaderResource::getVertexShaderAlignment);

	state["oz"]["ShaderResource"].setClass(metaTable);
}
