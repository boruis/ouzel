
#include "ouzel_scene_Camera_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_camera(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Camera, kaguya::MultipleBase<ouzel::scene::Actor, ouzel::scene::ActorContainer, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Camera(Matrix4 aProjection),
		ouzel::scene::Camera(const Size2 &aTargetContentSize, Camera::ScaleMode aScaleMode),
		ouzel::scene::Camera(float aFov, float aNearPlane, float aFarPlane)
	>();

	//PublicFunc
	metaTable.addFunction("setType", &ouzel::scene::Camera::setType);
	metaTable.addFunction("getType", &ouzel::scene::Camera::getType);
	metaTable.addFunction("setFOV", &ouzel::scene::Camera::setFOV);
	metaTable.addFunction("getFOV", &ouzel::scene::Camera::getFOV);
	metaTable.addFunction("setNearPlane", &ouzel::scene::Camera::setNearPlane);
	metaTable.addFunction("getNearPlane", &ouzel::scene::Camera::getNearPlane);
	metaTable.addFunction("setFarPlane", &ouzel::scene::Camera::setFarPlane);
	metaTable.addFunction("getFarPlane", &ouzel::scene::Camera::getFarPlane);
	metaTable.addFunction("getProjection", &ouzel::scene::Camera::getProjection);
	metaTable.addFunction("recalculateProjection", &ouzel::scene::Camera::recalculateProjection);
	metaTable.addFunction("getViewProjection", &ouzel::scene::Camera::getViewProjection);
	metaTable.addFunction("getRenderViewProjection", &ouzel::scene::Camera::getRenderViewProjection);
	metaTable.addFunction("getInverseViewProjection", &ouzel::scene::Camera::getInverseViewProjection);
	metaTable.addFunction("convertNormalizedToWorld", &ouzel::scene::Camera::convertNormalizedToWorld);
	metaTable.addFunction("convertWorldToNormalized", &ouzel::scene::Camera::convertWorldToNormalized);
	metaTable.addFunction("checkVisibility", &ouzel::scene::Camera::checkVisibility);
	metaTable.addFunction("setViewport", &ouzel::scene::Camera::setViewport);
	metaTable.addFunction("getViewport", &ouzel::scene::Camera::getViewport);
	metaTable.addFunction("getRenderViewport", &ouzel::scene::Camera::getRenderViewport);
	metaTable.addFunction("setScaleMode", &ouzel::scene::Camera::setScaleMode);
	metaTable.addFunction("getScaleMode", &ouzel::scene::Camera::getScaleMode);
	metaTable.addFunction("setTargetContentSize", &ouzel::scene::Camera::setTargetContentSize);
	metaTable.addFunction("getTargetContentSize", &ouzel::scene::Camera::getTargetContentSize);
	metaTable.addFunction("getContentSize", &ouzel::scene::Camera::getContentSize);
	metaTable.addFunction("getContentScale", &ouzel::scene::Camera::getContentScale);
	metaTable.addFunction("getContentPosition", &ouzel::scene::Camera::getContentPosition);
	metaTable.addFunction("setRenderTarget", &ouzel::scene::Camera::setRenderTarget);
	metaTable.addFunction("getRenderTarget", &ouzel::scene::Camera::getRenderTarget);
	metaTable.addFunction("getDepthWrite", &ouzel::scene::Camera::getDepthWrite);
	metaTable.addFunction("setDepthWrite", &ouzel::scene::Camera::setDepthWrite);
	metaTable.addFunction("getDepthTest", &ouzel::scene::Camera::getDepthTest);
	metaTable.addFunction("setDepthTest", &ouzel::scene::Camera::setDepthTest);
	metaTable.addFunction("getWireframe", &ouzel::scene::Camera::getWireframe);
	metaTable.addFunction("setWireframe", &ouzel::scene::Camera::setWireframe);

	state["oz"]["Camera"].setClass(metaTable);
}
