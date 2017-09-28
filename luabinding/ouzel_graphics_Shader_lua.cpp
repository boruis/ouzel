
#include "ouzel_graphics_Shader_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_shader(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::Shader>();

	//Constructor
	metaTable.setConstructors<
		ouzel::graphics::Shader()
	>();

	//PublicFunc
	metaTable.addFunction("getResource", &ouzel::graphics::Shader::getResource);
	metaTable.addFunction("getVertexAttributes", &ouzel::graphics::Shader::getVertexAttributes);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::graphics::Shader::*)(const std::vector< uint8_t > &newPixelShader, const std::vector< uint8_t > &newVertexShader, const std::vector< VertexAttribute > &newVertexAttributes, const std::vector< ouzel::graphics::Shader::ConstantInfo > &newPixelShaderConstantInfo, const std::vector< ouzel::graphics::Shader::ConstantInfo > &newVertexShaderConstantInfo, uint32_t newPixelShaderDataAlignment, uint32_t newVertexShaderDataAlignment, const std::string &pixelShaderFunction, const std::string &vertexShaderFunction)>(&ouzel::graphics::Shader::init);
	auto initPtr2 = static_cast<bool(ouzel::graphics::Shader::*)(const std::string &newPixelShader, const std::string &newVertexShader, const std::vector< VertexAttribute > &newVertexAttributes, const std::vector< ouzel::graphics::Shader::ConstantInfo > &newPixelShaderConstantInfo, const std::vector< ouzel::graphics::Shader::ConstantInfo > &newVertexShaderConstantInfo, uint32_t newPixelShaderDataAlignment, uint32_t newVertexShaderDataAlignment, const std::string &newPixelShaderFunction, const std::string &newVertexShaderFunction)>(&ouzel::graphics::Shader::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2);


	state["oz"]["Shader"].setClass(metaTable);
}
