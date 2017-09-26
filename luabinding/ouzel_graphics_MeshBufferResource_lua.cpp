
#include "ouzel_graphics_MeshBufferResource_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_meshbufferresource(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::MeshBufferResource>();

	//PublicFunc
	metaTable.addFunction("init", &ouzel::graphics::MeshBufferResource::init);
	metaTable.addFunction("getIndexSize", &ouzel::graphics::MeshBufferResource::getIndexSize);
	metaTable.addFunction("setIndexSize", &ouzel::graphics::MeshBufferResource::setIndexSize);
	metaTable.addFunction("getIndexBuffer", &ouzel::graphics::MeshBufferResource::getIndexBuffer);
	metaTable.addFunction("setIndexBuffer", &ouzel::graphics::MeshBufferResource::setIndexBuffer);
	metaTable.addFunction("getVertexSize", &ouzel::graphics::MeshBufferResource::getVertexSize);
	metaTable.addFunction("getVertexAttributes", &ouzel::graphics::MeshBufferResource::getVertexAttributes);
	metaTable.addFunction("setVertexAttributes", &ouzel::graphics::MeshBufferResource::setVertexAttributes);
	metaTable.addFunction("getVertexBuffer", &ouzel::graphics::MeshBufferResource::getVertexBuffer);
	metaTable.addFunction("setVertexBuffer", &ouzel::graphics::MeshBufferResource::setVertexBuffer);

	state["oz"]["MeshBufferResource"].setClass(metaTable);
}
