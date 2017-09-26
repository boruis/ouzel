
#include "ouzel_Color_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_color(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Color>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Color(),
		ouzel::Color(uint32_t color),
		ouzel::Color(const std::string &color),
		ouzel::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha),
		ouzel::Color(const Vector3 &vec),
		ouzel::Color(const Vector4 &vec)
	>();

	//PublicFunc
	metaTable.addFunction("normR", &ouzel::Color::normR);
	metaTable.addFunction("normG", &ouzel::Color::normG);
	metaTable.addFunction("normB", &ouzel::Color::normB);
	metaTable.addFunction("normA", &ouzel::Color::normA);
	metaTable.addFunction("getIntValue", &ouzel::Color::getIntValue);

	state["oz"]["Color"].setClass(metaTable);
}
