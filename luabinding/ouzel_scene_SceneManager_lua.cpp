
#include "ouzel_scene_SceneManager_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

template <typename T>
void ouzel_luabinding_scenemanager(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::SceneManager>();

	//PublicFunc
	metaTable.addFunction("draw", &ouzel::scene::SceneManager::draw);
	metaTable.addFunction("removeScene", &ouzel::scene::SceneManager::removeScene);
	metaTable.addFunction("getScene", &ouzel::scene::SceneManager::getScene);

	//Overloaded funcs
	auto setScenePtr1 = static_cast<void(ouzel::scene::SceneManager::*)(Scene *scene)>(&ouzel::scene::SceneManager::setScene);
	auto setScenePtr2 = static_cast<void(ouzel::scene::SceneManager::*)(const std::unique_ptr< T > &scene)>(&ouzel::scene::SceneManager::setScene);
	auto setScenePtr3 = static_cast<void(ouzel::scene::SceneManager::*)(std::unique_ptr< T > &&scene)>(&ouzel::scene::SceneManager::setScene);
	auto setScenePtr4 = static_cast<bool(ouzel::scene::SceneManager::*)(const std::unique_ptr< T > &scene)>(&ouzel::scene::SceneManager::setScene);
	metaTable.addOverloadedFunctions("setScene", setScenePtr1, setScenePtr2, setScenePtr3, setScenePtr4);


	state["oz"]["SceneManager"].setClass(metaTable);
}
