
#include "ouzel_graphics_MeshBuffer_lua.hpp"

using namespace ouzel;
using namespace ouzel::graphics;

void ouzel_luabinding_meshbuffer(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::graphics::MeshBuffer>();

	//Constructor
	metaTable.setConstructors<
		ouzel::graphics::MeshBuffer()
	>();

	//PublicFunc
	metaTable.addFunction("init", &ouzel::graphics::MeshBuffer::init);
	metaTable.addFunction("getResource", &ouzel::graphics::MeshBuffer::getResource);
	metaTable.addFunction("getIndexSize", &ouzel::graphics::MeshBuffer::getIndexSize);
	metaTable.addFunction("setIndexSize", &ouzel::graphics::MeshBuffer::setIndexSize);
	metaTable.addFunction("getIndexBuffer", &ouzel::graphics::MeshBuffer::getIndexBuffer);
	metaTable.addFunction("setIndexBuffer", &ouzel::graphics::MeshBuffer::setIndexBuffer);
	metaTable.addFunction("getVertexAttributes", &ouzel::graphics::MeshBuffer::getVertexAttributes);
	metaTable.addFunction("setVertexAttributes", &ouzel::graphics::MeshBuffer::setVertexAttributes);
	metaTable.addFunction("getVertexBuffer", &ouzel::graphics::MeshBuffer::getVertexBuffer);
	metaTable.addFunction("setVertexBuffer", &ouzel::graphics::MeshBuffer::setVertexBuffer);

	state["oz"]["MeshBuffer"].setClass(metaTable);
}
