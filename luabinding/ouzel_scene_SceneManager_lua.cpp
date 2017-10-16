
#include "ouzel_scene_SceneManager_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_scenemanager(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::SceneManager, ouzel::Noncopyable>();

	//PublicFunc
	metaTable.addFunction("draw", &ouzel::scene::SceneManager::draw);
	metaTable.addFunction("removeScene", &ouzel::scene::SceneManager::removeScene);
	metaTable.addFunction("getScene", &ouzel::scene::SceneManager::getScene);

	//Overloaded funcs
	auto setScenePtr1 = static_cast<void(ouzel::scene::SceneManager::*)(Scene *scene)>(&ouzel::scene::SceneManager::setScene);
	metaTable.addOverloadedFunctions("setScene", setScenePtr1);


	state["oz"]["SceneManager"].setClass(metaTable);
}
