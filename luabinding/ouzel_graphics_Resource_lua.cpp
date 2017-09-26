
#include "ouzel_graphics_Resource_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_resource(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::Resource>();

	//Constructor
	metaTable.setConstructors<
		ouzel::graphics::Resource()
	>();

	//PublicFunc
	metaTable.addFunction("reload", &ouzel::graphics::Resource::reload);

	state["oz"]["Resource"].setClass(metaTable);
}
