
#include "ouzel_scene_ShapeRenderer_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_shaperenderer(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::ShapeRenderer, kaguya::MultipleBase<ouzel::scene::Component, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::ShapeRenderer()
	>();

	//PublicFunc
	metaTable.addFunction("draw", &ouzel::scene::ShapeRenderer::draw);
	metaTable.addFunction("clear", &ouzel::scene::ShapeRenderer::clear);
	metaTable.addFunction("line", &ouzel::scene::ShapeRenderer::line);
	metaTable.addFunction("circle", &ouzel::scene::ShapeRenderer::circle);
	metaTable.addFunction("rectangle", &ouzel::scene::ShapeRenderer::rectangle);
	metaTable.addFunction("polygon", &ouzel::scene::ShapeRenderer::polygon);
	metaTable.addFunction("curve", &ouzel::scene::ShapeRenderer::curve);
	metaTable.addFunction("getShader", &ouzel::scene::ShapeRenderer::getShader);
	metaTable.addFunction("setShader", &ouzel::scene::ShapeRenderer::setShader);
	metaTable.addFunction("getBlendState", &ouzel::scene::ShapeRenderer::getBlendState);
	metaTable.addFunction("setBlendState", &ouzel::scene::ShapeRenderer::setBlendState);

	state["oz"]["ShapeRenderer"].setClass(metaTable);
}
