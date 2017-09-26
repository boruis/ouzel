
#include "ouzel_scene_Actor_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

template <typename T>
void ouzel_luabinding_actor(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Actor>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Actor()
	>();

	//PublicFunc
	metaTable.addFunction("visit", &ouzel::scene::Actor::visit);
	metaTable.addFunction("draw", &ouzel::scene::Actor::draw);
	metaTable.addFunction("getPosition", &ouzel::scene::Actor::getPosition);
	metaTable.addFunction("setOrder", &ouzel::scene::Actor::setOrder);
	metaTable.addFunction("getOrder", &ouzel::scene::Actor::getOrder);
	metaTable.addFunction("getRotation", &ouzel::scene::Actor::getRotation);
	metaTable.addFunction("getScale", &ouzel::scene::Actor::getScale);
	metaTable.addFunction("setOpacity", &ouzel::scene::Actor::setOpacity);
	metaTable.addFunction("getOpacity", &ouzel::scene::Actor::getOpacity);
	metaTable.addFunction("setFlipX", &ouzel::scene::Actor::setFlipX);
	metaTable.addFunction("getFlipX", &ouzel::scene::Actor::getFlipX);
	metaTable.addFunction("setFlipY", &ouzel::scene::Actor::setFlipY);
	metaTable.addFunction("getFlipY", &ouzel::scene::Actor::getFlipY);
	metaTable.addFunction("setPickable", &ouzel::scene::Actor::setPickable);
	metaTable.addFunction("isPickable", &ouzel::scene::Actor::isPickable);
	metaTable.addFunction("isCullDisabled", &ouzel::scene::Actor::isCullDisabled);
	metaTable.addFunction("setCullDisabled", &ouzel::scene::Actor::setCullDisabled);
	metaTable.addFunction("setHidden", &ouzel::scene::Actor::setHidden);
	metaTable.addFunction("isHidden", &ouzel::scene::Actor::isHidden);
	metaTable.addFunction("isWorldHidden", &ouzel::scene::Actor::isWorldHidden);
	metaTable.addFunction("pointOn", &ouzel::scene::Actor::pointOn);
	metaTable.addFunction("shapeOverlaps", &ouzel::scene::Actor::shapeOverlaps);
	metaTable.addFunction("getLocalTransform", &ouzel::scene::Actor::getLocalTransform);
	metaTable.addFunction("getTransform", &ouzel::scene::Actor::getTransform);
	metaTable.addFunction("getInverseTransform", &ouzel::scene::Actor::getInverseTransform);
	metaTable.addFunction("updateTransform", &ouzel::scene::Actor::updateTransform);
	metaTable.addFunction("getWorldPosition", &ouzel::scene::Actor::getWorldPosition);
	metaTable.addFunction("getWorldOrder", &ouzel::scene::Actor::getWorldOrder);
	metaTable.addFunction("convertWorldToLocal", &ouzel::scene::Actor::convertWorldToLocal);
	metaTable.addFunction("convertLocalToWorld", &ouzel::scene::Actor::convertLocalToWorld);
	metaTable.addFunction("getParent", &ouzel::scene::Actor::getParent);
	metaTable.addFunction("removeFromParent", &ouzel::scene::Actor::removeFromParent);
	metaTable.addFunction("removeAllComponents", &ouzel::scene::Actor::removeAllComponents);
	metaTable.addFunction("getBoundingBox", &ouzel::scene::Actor::getBoundingBox);

	//Overloaded funcs
	auto addComponentPtr1 = static_cast<void(ouzel::scene::Actor::*)(Component *component)>(&ouzel::scene::Actor::addComponent);
	auto addComponentPtr2 = static_cast<void(ouzel::scene::Actor::*)(const std::unique_ptr< T > &component)>(&ouzel::scene::Actor::addComponent);
	auto addComponentPtr3 = static_cast<void(ouzel::scene::Actor::*)(std::unique_ptr< T > &&component)>(&ouzel::scene::Actor::addComponent);
	metaTable.addOverloadedFunctions("addComponent", addComponentPtr1, addComponentPtr2, addComponentPtr3);

	auto getComponentsPtr1 = static_cast<const std::vector< Component * > &(ouzel::scene::Actor::*)() const>(&ouzel::scene::Actor::getComponents);
	auto getComponentsPtr2 = static_cast<std::vector< Component * >(ouzel::scene::Actor::*)(uint32_t type) const>(&ouzel::scene::Actor::getComponents);
	metaTable.addOverloadedFunctions("getComponents", getComponentsPtr1, getComponentsPtr2);

	auto removeComponentPtr1 = static_cast<bool(ouzel::scene::Actor::*)(Component *component)>(&ouzel::scene::Actor::removeComponent);
	auto removeComponentPtr2 = static_cast<void(ouzel::scene::Actor::*)(const std::unique_ptr< T > &component)>(&ouzel::scene::Actor::removeComponent);
	metaTable.addOverloadedFunctions("removeComponent", removeComponentPtr1, removeComponentPtr2);

	auto setPositionPtr1 = static_cast<void(ouzel::scene::Actor::*)(const Vector2 &newPosition)>(&ouzel::scene::Actor::setPosition);
	auto setPositionPtr2 = static_cast<void(ouzel::scene::Actor::*)(const Vector3 &newPosition)>(&ouzel::scene::Actor::setPosition);
	metaTable.addOverloadedFunctions("setPosition", setPositionPtr1, setPositionPtr2);

	auto setRotationPtr1 = static_cast<void(ouzel::scene::Actor::*)(const Quaternion &newRotation)>(&ouzel::scene::Actor::setRotation);
	auto setRotationPtr2 = static_cast<void(ouzel::scene::Actor::*)(const Vector3 &newRotation)>(&ouzel::scene::Actor::setRotation);
	auto setRotationPtr3 = static_cast<void(ouzel::scene::Actor::*)(float newRotation)>(&ouzel::scene::Actor::setRotation);
	metaTable.addOverloadedFunctions("setRotation", setRotationPtr1, setRotationPtr2, setRotationPtr3);

	auto setScalePtr1 = static_cast<void(ouzel::scene::Actor::*)(const Vector2 &newScale)>(&ouzel::scene::Actor::setScale);
	auto setScalePtr2 = static_cast<void(ouzel::scene::Actor::*)(const Vector3 &newScale)>(&ouzel::scene::Actor::setScale);
	metaTable.addOverloadedFunctions("setScale", setScalePtr1, setScalePtr2);


	state["oz"]["Actor"].setClass(metaTable);
}
