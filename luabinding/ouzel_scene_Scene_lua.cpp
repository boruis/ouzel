
#include "ouzel_scene_Scene_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

template <typename T>
void ouzel_luabinding_scene(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Scene>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Scene()
	>();

	//PublicFunc
	metaTable.addFunction("draw", &ouzel::scene::Scene::draw);
	metaTable.addFunction("removeAllLayers", &ouzel::scene::Scene::removeAllLayers);
	metaTable.addFunction("hasLayer", &ouzel::scene::Scene::hasLayer);
	metaTable.addFunction("getLayers", &ouzel::scene::Scene::getLayers);
	metaTable.addFunction("recalculateProjection", &ouzel::scene::Scene::recalculateProjection);
	metaTable.addFunction("pickActor", &ouzel::scene::Scene::pickActor);

	//Overloaded funcs
	auto addLayerPtr1 = static_cast<void(ouzel::scene::Scene::*)(Layer *layer)>(&ouzel::scene::Scene::addLayer);
	auto addLayerPtr2 = static_cast<void(ouzel::scene::Scene::*)(const std::unique_ptr< T > &layer)>(&ouzel::scene::Scene::addLayer);
	auto addLayerPtr3 = static_cast<void(ouzel::scene::Scene::*)(std::unique_ptr< T > &&layer)>(&ouzel::scene::Scene::addLayer);
	metaTable.addOverloadedFunctions("addLayer", addLayerPtr1, addLayerPtr2, addLayerPtr3);

	auto pickActorsPtr1 = static_cast<std::vector< std::pair< Actor *, ouzel::Vector3 > >(ouzel::scene::Scene::*)(const Vector2 &position, bool renderTargets) const>(&ouzel::scene::Scene::pickActors);
	auto pickActorsPtr2 = static_cast<std::vector< Actor * >(ouzel::scene::Scene::*)(const std::vector< Vector2 > &edges, bool renderTargets) const>(&ouzel::scene::Scene::pickActors);
	metaTable.addOverloadedFunctions("pickActors", pickActorsPtr1, pickActorsPtr2);

	auto removeLayerPtr1 = static_cast<bool(ouzel::scene::Scene::*)(Layer *layer)>(&ouzel::scene::Scene::removeLayer);
	auto removeLayerPtr2 = static_cast<bool(ouzel::scene::Scene::*)(const std::unique_ptr< T > &layer)>(&ouzel::scene::Scene::removeLayer);
	metaTable.addOverloadedFunctions("removeLayer", removeLayerPtr1, removeLayerPtr2);


	state["oz"]["Scene"].setClass(metaTable);
}
