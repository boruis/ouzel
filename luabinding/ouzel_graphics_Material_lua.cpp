
#include "ouzel_graphics_Material_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_material(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::Material, ouzel::Noncopyable>();

	state["oz"]["Material"].setClass(metaTable);
}
