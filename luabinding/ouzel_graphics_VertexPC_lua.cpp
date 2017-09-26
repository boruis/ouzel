
#include "ouzel_graphics_VertexPC_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_vertexpc(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::VertexPC>();

	//Constructor
	metaTable.setConstructors<
		ouzel::graphics::VertexPC(),
		ouzel::graphics::VertexPC(const Vector3 &aPosition, Color aColor)
	>();

	state["oz"]["VertexPC"].setClass(metaTable);
}
