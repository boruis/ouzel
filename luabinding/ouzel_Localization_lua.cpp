
#include "ouzel_Localization_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_localization(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Localization>();

	//PublicFunc
	metaTable.addFunction("addLanguage", &ouzel::Localization::addLanguage);
	metaTable.addFunction("setLanguage", &ouzel::Localization::setLanguage);
	metaTable.addFunction("getString", &ouzel::Localization::getString);

	state["oz"]["Localization"].setClass(metaTable);
}
