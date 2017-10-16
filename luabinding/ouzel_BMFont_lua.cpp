
#include "ouzel_BMFont_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_bmfont(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::BMFont, kaguya::MultipleBase<ouzel::Font, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::BMFont(),
		ouzel::BMFont(const std::string &filename, bool mipmaps)
	>();

	//PublicFunc
	metaTable.addFunction("getVertices", &ouzel::BMFont::getVertices);

	state["oz"]["BMFont"].setClass(metaTable);
}
