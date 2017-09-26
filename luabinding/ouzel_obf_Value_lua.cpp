
#include "ouzel_obf_Value_lua.hpp"

using namespace ouzel;
using namespace ouzel::obf;

void ouzel_luabinding_value(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::obf::Value>();

	//Constructor
	metaTable.setConstructors<
		ouzel::obf::Value(),
		ouzel::obf::Value(Type aType),
		ouzel::obf::Value(uint8_t value),
		ouzel::obf::Value(uint16_t value),
		ouzel::obf::Value(uint32_t value),
		ouzel::obf::Value(uint64_t value),
		ouzel::obf::Value(float value),
		ouzel::obf::Value(double value),
		ouzel::obf::Value(const std::string &value),
		ouzel::obf::Value(const std::vector< uint8_t > &value),
		ouzel::obf::Value(const std::map< uint32_t, Value > &value),
		ouzel::obf::Value(const std::vector< Value > &value)
	>();

	//PublicFunc
	metaTable.addFunction("getType", &ouzel::obf::Value::getType);
	metaTable.addFunction("isIntType", &ouzel::obf::Value::isIntType);
	metaTable.addFunction("isFloatType", &ouzel::obf::Value::isFloatType);
	metaTable.addFunction("isStringType", &ouzel::obf::Value::isStringType);
	metaTable.addFunction("decode", &ouzel::obf::Value::decode);
	metaTable.addFunction("encode", &ouzel::obf::Value::encode);
	metaTable.addFunction("asInt8", &ouzel::obf::Value::asInt8);
	metaTable.addFunction("asUInt8", &ouzel::obf::Value::asUInt8);
	metaTable.addFunction("asInt16", &ouzel::obf::Value::asInt16);
	metaTable.addFunction("asUInt16", &ouzel::obf::Value::asUInt16);
	metaTable.addFunction("asInt32", &ouzel::obf::Value::asInt32);
	metaTable.addFunction("asUInt32", &ouzel::obf::Value::asUInt32);
	metaTable.addFunction("asInt64", &ouzel::obf::Value::asInt64);
	metaTable.addFunction("asUInt64", &ouzel::obf::Value::asUInt64);
	metaTable.addFunction("asFloat", &ouzel::obf::Value::asFloat);
	metaTable.addFunction("asDouble", &ouzel::obf::Value::asDouble);
	metaTable.addFunction("asString", &ouzel::obf::Value::asString);
	metaTable.addFunction("asByteArray", &ouzel::obf::Value::asByteArray);
	metaTable.addFunction("asMap", &ouzel::obf::Value::asMap);
	metaTable.addFunction("asVector", &ouzel::obf::Value::asVector);
	metaTable.addFunction("asDictionary", &ouzel::obf::Value::asDictionary);
	metaTable.addFunction("getSize", &ouzel::obf::Value::getSize);
	metaTable.addFunction("append", &ouzel::obf::Value::append);

	//Overloaded funcs
	auto beginPtr1 = static_cast<std::vector< Value >::iterator(ouzel::obf::Value::*)()>(&ouzel::obf::Value::begin);
	auto beginPtr2 = static_cast<std::vector< Value >::const_iterator(ouzel::obf::Value::*)() const>(&ouzel::obf::Value::begin);
	metaTable.addOverloadedFunctions("begin", beginPtr1, beginPtr2);

	auto endPtr1 = static_cast<std::vector< Value >::iterator(ouzel::obf::Value::*)()>(&ouzel::obf::Value::end);
	auto endPtr2 = static_cast<std::vector< Value >::const_iterator(ouzel::obf::Value::*)() const>(&ouzel::obf::Value::end);
	metaTable.addOverloadedFunctions("end", endPtr1, endPtr2);

	auto hasElementPtr1 = static_cast<bool(ouzel::obf::Value::*)(uint32_t key) const>(&ouzel::obf::Value::hasElement);
	auto hasElementPtr2 = static_cast<bool(ouzel::obf::Value::*)(const std::string &key) const>(&ouzel::obf::Value::hasElement);
	metaTable.addOverloadedFunctions("hasElement", hasElementPtr1, hasElementPtr2);


	state["oz"]["Value"].setClass(metaTable);
}
