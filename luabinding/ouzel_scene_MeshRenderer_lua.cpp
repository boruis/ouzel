
#include "ouzel_scene_MeshRenderer_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_meshrenderer(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::MeshRenderer, kaguya::MultipleBase<ouzel::scene::Component, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::MeshRenderer()
	>();

	state["oz"]["MeshRenderer"].setClass(metaTable);
}
