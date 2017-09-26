
#include "ouzel_scene_Layer_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_layer(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Layer>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Layer()
	>();

	//PublicFunc
	metaTable.addFunction("draw", &ouzel::scene::Layer::draw);
	metaTable.addFunction("getCameras", &ouzel::scene::Layer::getCameras);
	metaTable.addFunction("pickActor", &ouzel::scene::Layer::pickActor);
	metaTable.addFunction("getOrder", &ouzel::scene::Layer::getOrder);
	metaTable.addFunction("setOrder", &ouzel::scene::Layer::setOrder);
	metaTable.addFunction("getScene", &ouzel::scene::Layer::getScene);
	metaTable.addFunction("removeFromScene", &ouzel::scene::Layer::removeFromScene);

	//Overloaded funcs
	auto pickActorsPtr1 = static_cast<std::vector< std::pair< Actor *, ouzel::Vector3 > >(ouzel::scene::Layer::*)(const Vector2 &position, bool renderTargets) const>(&ouzel::scene::Layer::pickActors);
	auto pickActorsPtr2 = static_cast<std::vector< Actor * >(ouzel::scene::Layer::*)(const std::vector< Vector2 > &edges, bool renderTargets) const>(&ouzel::scene::Layer::pickActors);
	metaTable.addOverloadedFunctions("pickActors", pickActorsPtr1, pickActorsPtr2);


	state["oz"]["Layer"].setClass(metaTable);
}
