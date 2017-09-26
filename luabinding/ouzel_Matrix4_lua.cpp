
#include "ouzel_Matrix4_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_matrix4(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Matrix4>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Matrix4(),
		ouzel::Matrix4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44),
		ouzel::Matrix4(const float *array),
		ouzel::Matrix4(const Matrix4 &copy)
	>();

	//PublicFunc
	metaTable.addFunction("getFrustumLeftPlane", &ouzel::Matrix4::getFrustumLeftPlane);
	metaTable.addFunction("getFrustumRightPlane", &ouzel::Matrix4::getFrustumRightPlane);
	metaTable.addFunction("getFrustumBottomPlane", &ouzel::Matrix4::getFrustumBottomPlane);
	metaTable.addFunction("getFrustumTopPlane", &ouzel::Matrix4::getFrustumTopPlane);
	metaTable.addFunction("getFrustumNearPlane", &ouzel::Matrix4::getFrustumNearPlane);
	metaTable.addFunction("getFrustumFarPlane", &ouzel::Matrix4::getFrustumFarPlane);
	metaTable.addFunction("getFrustum", &ouzel::Matrix4::getFrustum);
	metaTable.addFunction("determinant", &ouzel::Matrix4::determinant);
	metaTable.addFunction("getUpVector", &ouzel::Matrix4::getUpVector);
	metaTable.addFunction("getDownVector", &ouzel::Matrix4::getDownVector);
	metaTable.addFunction("getLeftVector", &ouzel::Matrix4::getLeftVector);
	metaTable.addFunction("getRightVector", &ouzel::Matrix4::getRightVector);
	metaTable.addFunction("getForwardVector", &ouzel::Matrix4::getForwardVector);
	metaTable.addFunction("getBackVector", &ouzel::Matrix4::getBackVector);
	metaTable.addFunction("isIdentity", &ouzel::Matrix4::isIdentity);
	metaTable.addFunction("setIdentity", &ouzel::Matrix4::setIdentity);
	metaTable.addFunction("setZero", &ouzel::Matrix4::setZero);
	metaTable.addFunction("getTranslation", &ouzel::Matrix4::getTranslation);
	metaTable.addFunction("getScale", &ouzel::Matrix4::getScale);
	metaTable.addFunction("getRotation", &ouzel::Matrix4::getRotation);

	//PublicStaticFunc
	metaTable.addStaticFunction("createPerspective", &ouzel::Matrix4::createPerspective);
	metaTable.addStaticFunction("createOrthographicFromSize", &ouzel::Matrix4::createOrthographicFromSize);
	metaTable.addStaticFunction("createOrthographicOffCenter", &ouzel::Matrix4::createOrthographicOffCenter);
	metaTable.addStaticFunction("createRotation", &ouzel::Matrix4::createRotation);
	metaTable.addStaticFunction("createRotationX", &ouzel::Matrix4::createRotationX);
	metaTable.addStaticFunction("createRotationY", &ouzel::Matrix4::createRotationY);
	metaTable.addStaticFunction("createRotationZ", &ouzel::Matrix4::createRotationZ);

	//Overloaded funcs
	auto addPtr1 = static_cast<void(ouzel::Matrix4::*)(float scalar)>(&ouzel::Matrix4::add);
	auto addPtr2 = static_cast<void(ouzel::Matrix4::*)(float scalar, Matrix4 &dst)>(&ouzel::Matrix4::add);
	auto addPtr3 = static_cast<void(ouzel::Matrix4::*)(const Matrix4 &matrix)>(&ouzel::Matrix4::add);
	auto addPtr4 = static_cast<void(*)(const Matrix4 &m1, const Matrix4 &m2, Matrix4 &dst)>(&ouzel::Matrix4::add);
	metaTable.addOverloadedFunctions("add", addPtr1, addPtr2, addPtr3, addPtr4);

	auto createBillboardPtr1 = static_cast<void(*)(const Vector3 &objectPosition, const Vector3 &cameraPosition, const Vector3 &cameraUpVector, Matrix4 &dst)>(&ouzel::Matrix4::createBillboard);
	auto createBillboardPtr2 = static_cast<void(*)(const Vector3 &objectPosition, const Vector3 &cameraPosition, const Vector3 &cameraUpVector, const Vector3 &cameraForwardVector, Matrix4 &dst)>(&ouzel::Matrix4::createBillboard);
	metaTable.addOverloadedFunctions("createBillboard", createBillboardPtr1, createBillboardPtr2);

	auto createLookAtPtr1 = static_cast<void(*)(const Vector3 &eyePosition, const Vector3 &targetPosition, const Vector3 &up, Matrix4 &dst)>(&ouzel::Matrix4::createLookAt);
	auto createLookAtPtr2 = static_cast<void(*)(float eyePositionX, float eyePositionY, float eyePositionZ, float targetCenterX, float targetCenterY, float targetCenterZ, float upX, float upY, float upZ, Matrix4 &dst)>(&ouzel::Matrix4::createLookAt);
	metaTable.addOverloadedFunctions("createLookAt", createLookAtPtr1, createLookAtPtr2);

	auto createScalePtr1 = static_cast<void(*)(const Vector3 &scale, Matrix4 &dst)>(&ouzel::Matrix4::createScale);
	auto createScalePtr2 = static_cast<void(*)(float xScale, float yScale, float zScale, Matrix4 &dst)>(&ouzel::Matrix4::createScale);
	metaTable.addOverloadedFunctions("createScale", createScalePtr1, createScalePtr2);

	auto createTranslationPtr1 = static_cast<void(*)(const Vector3 &translation, Matrix4 &dst)>(&ouzel::Matrix4::createTranslation);
	auto createTranslationPtr2 = static_cast<void(*)(float xTranslation, float yTranslation, float zTranslation, Matrix4 &dst)>(&ouzel::Matrix4::createTranslation);
	metaTable.addOverloadedFunctions("createTranslation", createTranslationPtr1, createTranslationPtr2);

	auto invertPtr1 = static_cast<bool(ouzel::Matrix4::*)()>(&ouzel::Matrix4::invert);
	auto invertPtr2 = static_cast<bool(ouzel::Matrix4::*)(Matrix4 &dst) const>(&ouzel::Matrix4::invert);
	metaTable.addOverloadedFunctions("invert", invertPtr1, invertPtr2);

	auto multiplyPtr1 = static_cast<void(ouzel::Matrix4::*)(float scalar)>(&ouzel::Matrix4::multiply);
	auto multiplyPtr2 = static_cast<void(ouzel::Matrix4::*)(float scalar, Matrix4 &dst) const>(&ouzel::Matrix4::multiply);
	auto multiplyPtr3 = static_cast<void(ouzel::Matrix4::*)(const Matrix4 &matrix)>(&ouzel::Matrix4::multiply);
	auto multiplyPtr4 = static_cast<void(*)(const Matrix4 &m, float scalar, Matrix4 &dst)>(&ouzel::Matrix4::multiply);
	auto multiplyPtr5 = static_cast<void(*)(const Matrix4 &m1, const Matrix4 &m2, Matrix4 &dst)>(&ouzel::Matrix4::multiply);
	metaTable.addOverloadedFunctions("multiply", multiplyPtr1, multiplyPtr2, multiplyPtr3, multiplyPtr4, multiplyPtr5);

	auto negatePtr1 = static_cast<void(ouzel::Matrix4::*)()>(&ouzel::Matrix4::negate);
	auto negatePtr2 = static_cast<void(ouzel::Matrix4::*)(Matrix4 &dst) const>(&ouzel::Matrix4::negate);
	metaTable.addOverloadedFunctions("negate", negatePtr1, negatePtr2);

	auto rotatePtr1 = static_cast<void(ouzel::Matrix4::*)(const Vector3 &axis, float angle)>(&ouzel::Matrix4::rotate);
	auto rotatePtr2 = static_cast<void(ouzel::Matrix4::*)(const Vector3 &axis, float angle, Matrix4 &dst) const>(&ouzel::Matrix4::rotate);
	metaTable.addOverloadedFunctions("rotate", rotatePtr1, rotatePtr2);

	auto rotateXPtr1 = static_cast<void(ouzel::Matrix4::*)(float angle)>(&ouzel::Matrix4::rotateX);
	auto rotateXPtr2 = static_cast<void(ouzel::Matrix4::*)(float angle, Matrix4 &dst) const>(&ouzel::Matrix4::rotateX);
	metaTable.addOverloadedFunctions("rotateX", rotateXPtr1, rotateXPtr2);

	auto rotateYPtr1 = static_cast<void(ouzel::Matrix4::*)(float angle)>(&ouzel::Matrix4::rotateY);
	auto rotateYPtr2 = static_cast<void(ouzel::Matrix4::*)(float angle, Matrix4 &dst) const>(&ouzel::Matrix4::rotateY);
	metaTable.addOverloadedFunctions("rotateY", rotateYPtr1, rotateYPtr2);

	auto rotateZPtr1 = static_cast<void(ouzel::Matrix4::*)(float angle)>(&ouzel::Matrix4::rotateZ);
	auto rotateZPtr2 = static_cast<void(ouzel::Matrix4::*)(float angle, Matrix4 &dst) const>(&ouzel::Matrix4::rotateZ);
	metaTable.addOverloadedFunctions("rotateZ", rotateZPtr1, rotateZPtr2);

	auto scalePtr1 = static_cast<void(ouzel::Matrix4::*)(float value)>(&ouzel::Matrix4::scale);
	auto scalePtr2 = static_cast<void(ouzel::Matrix4::*)(float value, Matrix4 &dst) const>(&ouzel::Matrix4::scale);
	auto scalePtr3 = static_cast<void(ouzel::Matrix4::*)(float xScale, float yScale, float zScale)>(&ouzel::Matrix4::scale);
	auto scalePtr4 = static_cast<void(ouzel::Matrix4::*)(float xScale, float yScale, float zScale, Matrix4 &dst) const>(&ouzel::Matrix4::scale);
	auto scalePtr5 = static_cast<void(ouzel::Matrix4::*)(const Vector3 &s)>(&ouzel::Matrix4::scale);
	auto scalePtr6 = static_cast<void(ouzel::Matrix4::*)(const Vector3 &s, Matrix4 &dst) const>(&ouzel::Matrix4::scale);
	metaTable.addOverloadedFunctions("scale", scalePtr1, scalePtr2, scalePtr3, scalePtr4, scalePtr5, scalePtr6);

	auto setPtr1 = static_cast<void(ouzel::Matrix4::*)(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)>(&ouzel::Matrix4::set);
	auto setPtr2 = static_cast<void(ouzel::Matrix4::*)(const float *array)>(&ouzel::Matrix4::set);
	metaTable.addOverloadedFunctions("set", setPtr1, setPtr2);

	auto subtractPtr1 = static_cast<void(ouzel::Matrix4::*)(const Matrix4 &matrix)>(&ouzel::Matrix4::subtract);
	auto subtractPtr2 = static_cast<void(*)(const Matrix4 &m1, const Matrix4 &m2, Matrix4 &dst)>(&ouzel::Matrix4::subtract);
	metaTable.addOverloadedFunctions("subtract", subtractPtr1, subtractPtr2);

	auto transformPointPtr1 = static_cast<void(ouzel::Matrix4::*)(Vector3 &point) const>(&ouzel::Matrix4::transformPoint);
	auto transformPointPtr2 = static_cast<void(ouzel::Matrix4::*)(const Vector3 &point, Vector3 &dst) const>(&ouzel::Matrix4::transformPoint);
	metaTable.addOverloadedFunctions("transformPoint", transformPointPtr1, transformPointPtr2);

	auto transformVectorPtr1 = static_cast<void(ouzel::Matrix4::*)(Vector3 &vector) const>(&ouzel::Matrix4::transformVector);
	auto transformVectorPtr2 = static_cast<void(ouzel::Matrix4::*)(const Vector3 &vector, Vector3 &dst) const>(&ouzel::Matrix4::transformVector);
	auto transformVectorPtr3 = static_cast<void(ouzel::Matrix4::*)(float x, float y, float z, float w, Vector3 &dst) const>(&ouzel::Matrix4::transformVector);
	auto transformVectorPtr4 = static_cast<void(ouzel::Matrix4::*)(Vector4 &vector) const>(&ouzel::Matrix4::transformVector);
	auto transformVectorPtr5 = static_cast<void(ouzel::Matrix4::*)(const Vector4 &vector, Vector4 &dst) const>(&ouzel::Matrix4::transformVector);
	metaTable.addOverloadedFunctions("transformVector", transformVectorPtr1, transformVectorPtr2, transformVectorPtr3, transformVectorPtr4, transformVectorPtr5);

	auto translatePtr1 = static_cast<void(ouzel::Matrix4::*)(float x, float y, float z)>(&ouzel::Matrix4::translate);
	auto translatePtr2 = static_cast<void(ouzel::Matrix4::*)(float x, float y, float z, Matrix4 &dst) const>(&ouzel::Matrix4::translate);
	auto translatePtr3 = static_cast<void(ouzel::Matrix4::*)(const Vector3 &t)>(&ouzel::Matrix4::translate);
	auto translatePtr4 = static_cast<void(ouzel::Matrix4::*)(const Vector3 &t, Matrix4 &dst) const>(&ouzel::Matrix4::translate);
	metaTable.addOverloadedFunctions("translate", translatePtr1, translatePtr2, translatePtr3, translatePtr4);

	auto transposePtr1 = static_cast<void(ouzel::Matrix4::*)()>(&ouzel::Matrix4::transpose);
	auto transposePtr2 = static_cast<void(ouzel::Matrix4::*)(Matrix4 &dst) const>(&ouzel::Matrix4::transpose);
	metaTable.addOverloadedFunctions("transpose", transposePtr1, transposePtr2);


	state["oz"]["Matrix4"].setClass(metaTable);
}
