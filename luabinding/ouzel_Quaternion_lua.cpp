
#include "ouzel_Quaternion_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_quaternion(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Quaternion>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Quaternion(),
		ouzel::Quaternion(float aX, float aY, float aZ, float aW),
		ouzel::Quaternion(const Quaternion &copy)
	>();

	//PublicFunc
	metaTable.addFunction("negate", &ouzel::Quaternion::negate);
	metaTable.addFunction("conjugate", &ouzel::Quaternion::conjugate);
	metaTable.addFunction("invert", &ouzel::Quaternion::invert);
	metaTable.addFunction("getNorm", &ouzel::Quaternion::getNorm);
	metaTable.addFunction("normalize", &ouzel::Quaternion::normalize);
	metaTable.addFunction("rotate", &ouzel::Quaternion::rotate);
	metaTable.addFunction("getRotation", &ouzel::Quaternion::getRotation);
	metaTable.addFunction("setEulerAngles", &ouzel::Quaternion::setEulerAngles);
	metaTable.addFunction("getEulerAngles", &ouzel::Quaternion::getEulerAngles);
	metaTable.addFunction("getEulerAngleX", &ouzel::Quaternion::getEulerAngleX);
	metaTable.addFunction("getEulerAngleY", &ouzel::Quaternion::getEulerAngleY);
	metaTable.addFunction("getEulerAngleZ", &ouzel::Quaternion::getEulerAngleZ);
	metaTable.addFunction("rotateVector", &ouzel::Quaternion::rotateVector);
	metaTable.addFunction("getRightVector", &ouzel::Quaternion::getRightVector);
	metaTable.addFunction("getUpVector", &ouzel::Quaternion::getUpVector);
	metaTable.addFunction("getForwardVector", &ouzel::Quaternion::getForwardVector);
	metaTable.addFunction("getMatrix", &ouzel::Quaternion::getMatrix);
	metaTable.addFunction("lerp", &ouzel::Quaternion::lerp);

	state["oz"]["Quaternion"].setClass(metaTable);
}
