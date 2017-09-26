
#include "ouzel_scene_TextRenderer_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_textrenderer(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::TextRenderer>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::TextRenderer(const std::string &fontFile, bool aMipmaps, float fontSize, const std::string &aText, Color aColor, const Vector2 &aTextAnchor)
	>();

	//PublicFunc
	metaTable.addFunction("draw", &ouzel::scene::TextRenderer::draw);
	metaTable.addFunction("setFont", &ouzel::scene::TextRenderer::setFont);
	metaTable.addFunction("setTextAnchor", &ouzel::scene::TextRenderer::setTextAnchor);
	metaTable.addFunction("getTextAnchor", &ouzel::scene::TextRenderer::getTextAnchor);
	metaTable.addFunction("setTextScale", &ouzel::scene::TextRenderer::setTextScale);
	metaTable.addFunction("getTextScale", &ouzel::scene::TextRenderer::getTextScale);
	metaTable.addFunction("setText", &ouzel::scene::TextRenderer::setText);
	metaTable.addFunction("getText", &ouzel::scene::TextRenderer::getText);
	metaTable.addFunction("getColor", &ouzel::scene::TextRenderer::getColor);
	metaTable.addFunction("setColor", &ouzel::scene::TextRenderer::setColor);
	metaTable.addFunction("getShader", &ouzel::scene::TextRenderer::getShader);
	metaTable.addFunction("setShader", &ouzel::scene::TextRenderer::setShader);
	metaTable.addFunction("getBlendState", &ouzel::scene::TextRenderer::getBlendState);
	metaTable.addFunction("setBlendState", &ouzel::scene::TextRenderer::setBlendState);

	state["oz"]["TextRenderer"].setClass(metaTable);
}
