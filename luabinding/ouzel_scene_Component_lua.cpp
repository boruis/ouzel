
#include "ouzel_scene_Component_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_component(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Component, ouzel::Noncopyable>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Component(uint32_t aType)
	>();

	//PublicFunc
	metaTable.addFunction("getType", &ouzel::scene::Component::getType);
	metaTable.addFunction("draw", &ouzel::scene::Component::draw);
	metaTable.addFunction("setBoundingBox", &ouzel::scene::Component::setBoundingBox);
	metaTable.addFunction("getBoundingBox", &ouzel::scene::Component::getBoundingBox);
	metaTable.addFunction("pointOn", &ouzel::scene::Component::pointOn);
	metaTable.addFunction("shapeOverlaps", &ouzel::scene::Component::shapeOverlaps);
	metaTable.addFunction("isHidden", &ouzel::scene::Component::isHidden);
	metaTable.addFunction("setHidden", &ouzel::scene::Component::setHidden);
	metaTable.addFunction("getActor", &ouzel::scene::Component::getActor);
	metaTable.addFunction("removeFromActor", &ouzel::scene::Component::removeFromActor);

	state["oz"]["Component"].setClass(metaTable);
}
