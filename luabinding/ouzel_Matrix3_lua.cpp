
#include "ouzel_Matrix3_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_matrix3(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Matrix3>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Matrix3(),
		ouzel::Matrix3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33),
		ouzel::Matrix3(const float *array),
		ouzel::Matrix3(const Matrix3 &copy)
	>();

	//PublicFunc
	metaTable.addFunction("determinant", &ouzel::Matrix3::determinant);
	metaTable.addFunction("isIdentity", &ouzel::Matrix3::isIdentity);
	metaTable.addFunction("negate", &ouzel::Matrix3::negate);
	metaTable.addFunction("setIdentity", &ouzel::Matrix3::setIdentity);
	metaTable.addFunction("setZero", &ouzel::Matrix3::setZero);

	//PublicStaticFunc
	metaTable.addStaticFunction("createRotation", &ouzel::Matrix3::createRotation);

	//Overloaded funcs
	auto addPtr1 = static_cast<void(ouzel::Matrix3::*)(float scalar)>(&ouzel::Matrix3::add);
	auto addPtr2 = static_cast<void(ouzel::Matrix3::*)(float scalar, Matrix3 &dst)>(&ouzel::Matrix3::add);
	auto addPtr3 = static_cast<void(ouzel::Matrix3::*)(const Matrix3 &matrix)>(&ouzel::Matrix3::add);
	auto addPtr4 = static_cast<void(*)(const Matrix3 &m1, const Matrix3 &m2, Matrix3 &dst)>(&ouzel::Matrix3::add);
	metaTable.addOverloadedFunctions("add", addPtr1, addPtr2, addPtr3, addPtr4);

	auto createScalePtr1 = static_cast<void(*)(const Vector2 &scale, Matrix3 &dst)>(&ouzel::Matrix3::createScale);
	auto createScalePtr2 = static_cast<void(*)(float xScale, float yScale, Matrix3 &dst)>(&ouzel::Matrix3::createScale);
	metaTable.addOverloadedFunctions("createScale", createScalePtr1, createScalePtr2);

	auto createTranslationPtr1 = static_cast<void(*)(const Vector2 &translation, Matrix3 &dst)>(&ouzel::Matrix3::createTranslation);
	auto createTranslationPtr2 = static_cast<void(*)(float xTranslation, float yTranslation, Matrix3 &dst)>(&ouzel::Matrix3::createTranslation);
	metaTable.addOverloadedFunctions("createTranslation", createTranslationPtr1, createTranslationPtr2);

	auto invertPtr1 = static_cast<bool(ouzel::Matrix3::*)()>(&ouzel::Matrix3::invert);
	auto invertPtr2 = static_cast<bool(ouzel::Matrix3::*)(Matrix3 &dst) const>(&ouzel::Matrix3::invert);
	metaTable.addOverloadedFunctions("invert", invertPtr1, invertPtr2);

	auto multiplyPtr1 = static_cast<void(ouzel::Matrix3::*)(float scalar)>(&ouzel::Matrix3::multiply);
	auto multiplyPtr2 = static_cast<void(ouzel::Matrix3::*)(float scalar, Matrix3 &dst) const>(&ouzel::Matrix3::multiply);
	auto multiplyPtr3 = static_cast<void(ouzel::Matrix3::*)(const Matrix3 &matrix)>(&ouzel::Matrix3::multiply);
	auto multiplyPtr4 = static_cast<void(*)(const Matrix3 &matrix, float scalar, Matrix3 &dst)>(&ouzel::Matrix3::multiply);
	auto multiplyPtr5 = static_cast<void(*)(const Matrix3 &m1, const Matrix3 &m2, Matrix3 &dst)>(&ouzel::Matrix3::multiply);
	metaTable.addOverloadedFunctions("multiply", multiplyPtr1, multiplyPtr2, multiplyPtr3, multiplyPtr4, multiplyPtr5);

	auto rotatePtr1 = static_cast<void(ouzel::Matrix3::*)(float angle)>(&ouzel::Matrix3::rotate);
	auto rotatePtr2 = static_cast<void(ouzel::Matrix3::*)(float angle, Matrix3 &dst) const>(&ouzel::Matrix3::rotate);
	metaTable.addOverloadedFunctions("rotate", rotatePtr1, rotatePtr2);

	auto scalePtr1 = static_cast<void(ouzel::Matrix3::*)(float value)>(&ouzel::Matrix3::scale);
	auto scalePtr2 = static_cast<void(ouzel::Matrix3::*)(float value, Matrix3 &dst) const>(&ouzel::Matrix3::scale);
	auto scalePtr3 = static_cast<void(ouzel::Matrix3::*)(float xScale, float yScale)>(&ouzel::Matrix3::scale);
	auto scalePtr4 = static_cast<void(ouzel::Matrix3::*)(float xScale, float yScale, Matrix3 &dst) const>(&ouzel::Matrix3::scale);
	auto scalePtr5 = static_cast<void(ouzel::Matrix3::*)(const Vector2 &s)>(&ouzel::Matrix3::scale);
	auto scalePtr6 = static_cast<void(ouzel::Matrix3::*)(const Vector2 &s, Matrix3 &dst) const>(&ouzel::Matrix3::scale);
	metaTable.addOverloadedFunctions("scale", scalePtr1, scalePtr2, scalePtr3, scalePtr4, scalePtr5, scalePtr6);

	auto setPtr1 = static_cast<void(ouzel::Matrix3::*)(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33)>(&ouzel::Matrix3::set);
	auto setPtr2 = static_cast<void(ouzel::Matrix3::*)(const float *array)>(&ouzel::Matrix3::set);
	metaTable.addOverloadedFunctions("set", setPtr1, setPtr2);

	auto subtractPtr1 = static_cast<void(ouzel::Matrix3::*)(const Matrix3 &matrix)>(&ouzel::Matrix3::subtract);
	auto subtractPtr2 = static_cast<void(*)(const Matrix3 &m1, const Matrix3 &m2, Matrix3 &dst)>(&ouzel::Matrix3::subtract);
	metaTable.addOverloadedFunctions("subtract", subtractPtr1, subtractPtr2);

	auto transformPointPtr1 = static_cast<void(ouzel::Matrix3::*)(Vector2 &point) const>(&ouzel::Matrix3::transformPoint);
	auto transformPointPtr2 = static_cast<void(ouzel::Matrix3::*)(const Vector2 &point, Vector2 &dst) const>(&ouzel::Matrix3::transformPoint);
	metaTable.addOverloadedFunctions("transformPoint", transformPointPtr1, transformPointPtr2);

	auto transformVectorPtr1 = static_cast<void(ouzel::Matrix3::*)(Vector2 &vector) const>(&ouzel::Matrix3::transformVector);
	auto transformVectorPtr2 = static_cast<void(ouzel::Matrix3::*)(const Vector2 &vector, Vector2 &dst) const>(&ouzel::Matrix3::transformVector);
	auto transformVectorPtr3 = static_cast<void(ouzel::Matrix3::*)(float x, float y, float z, Vector2 &dst) const>(&ouzel::Matrix3::transformVector);
	auto transformVectorPtr4 = static_cast<void(ouzel::Matrix3::*)(Vector3 &vector) const>(&ouzel::Matrix3::transformVector);
	auto transformVectorPtr5 = static_cast<void(ouzel::Matrix3::*)(const Vector3 &vector, Vector3 &dst) const>(&ouzel::Matrix3::transformVector);
	metaTable.addOverloadedFunctions("transformVector", transformVectorPtr1, transformVectorPtr2, transformVectorPtr3, transformVectorPtr4, transformVectorPtr5);

	auto translatePtr1 = static_cast<void(ouzel::Matrix3::*)(float x, float y)>(&ouzel::Matrix3::translate);
	auto translatePtr2 = static_cast<void(ouzel::Matrix3::*)(float x, float y, Matrix3 &dst) const>(&ouzel::Matrix3::translate);
	auto translatePtr3 = static_cast<void(ouzel::Matrix3::*)(const Vector2 &t)>(&ouzel::Matrix3::translate);
	auto translatePtr4 = static_cast<void(ouzel::Matrix3::*)(const Vector2 &t, Matrix3 &dst) const>(&ouzel::Matrix3::translate);
	metaTable.addOverloadedFunctions("translate", translatePtr1, translatePtr2, translatePtr3, translatePtr4);

	auto transposePtr1 = static_cast<void(ouzel::Matrix3::*)()>(&ouzel::Matrix3::transpose);
	auto transposePtr2 = static_cast<void(ouzel::Matrix3::*)(Matrix3 &dst) const>(&ouzel::Matrix3::transpose);
	metaTable.addOverloadedFunctions("transpose", transposePtr1, transposePtr2);


	state["oz"]["Matrix3"].setClass(metaTable);
}
