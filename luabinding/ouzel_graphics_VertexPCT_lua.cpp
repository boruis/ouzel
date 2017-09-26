
#include "ouzel_graphics_VertexPCT_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_vertexpct(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::VertexPCT>();

	//Constructor
	metaTable.setConstructors<
		ouzel::graphics::VertexPCT(),
		ouzel::graphics::VertexPCT(const Vector3 &aPosition, Color aColor, const Vector2 &aTexCoord)
	>();

	state["oz"]["VertexPCT"].setClass(metaTable);
}
