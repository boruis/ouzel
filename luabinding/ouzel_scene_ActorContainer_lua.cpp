
#include "ouzel_scene_ActorContainer_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_actorcontainer(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::ActorContainer, ouzel::Noncopyable>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::ActorContainer()
	>();

	//PublicFunc
	metaTable.addFunction("moveChildToBack", &ouzel::scene::ActorContainer::moveChildToBack);
	metaTable.addFunction("moveChildToFront", &ouzel::scene::ActorContainer::moveChildToFront);
	metaTable.addFunction("removeAllChildren", &ouzel::scene::ActorContainer::removeAllChildren);
	metaTable.addFunction("hasChild", &ouzel::scene::ActorContainer::hasChild);
	metaTable.addFunction("getChildren", &ouzel::scene::ActorContainer::getChildren);
	metaTable.addFunction("getLayer", &ouzel::scene::ActorContainer::getLayer);

	//Overloaded funcs
	auto addChildPtr1 = static_cast<void(ouzel::scene::ActorContainer::*)(Actor *actor)>(&ouzel::scene::ActorContainer::addChild);
	metaTable.addOverloadedFunctions("addChild", addChildPtr1);

	auto findActorsPtr1 = static_cast<void(ouzel::scene::ActorContainer::*)(const Vector2 &position, std::vector< std::pair< Actor *, Vector3 >> &actors) const>(&ouzel::scene::ActorContainer::findActors);
	auto findActorsPtr2 = static_cast<void(ouzel::scene::ActorContainer::*)(const std::vector< Vector2 > &edges, std::vector< Actor *> &actors) const>(&ouzel::scene::ActorContainer::findActors);
	metaTable.addOverloadedFunctions("findActors", findActorsPtr1, findActorsPtr2);

	auto removeChildPtr1 = static_cast<bool(ouzel::scene::ActorContainer::*)(Actor *actor)>(&ouzel::scene::ActorContainer::removeChild);
	metaTable.addOverloadedFunctions("removeChild", removeChildPtr1);


	state["oz"]["ActorContainer"].setClass(metaTable);
}
