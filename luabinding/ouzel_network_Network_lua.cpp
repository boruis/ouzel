
#include "ouzel_network_Network_lua.hpp"

using namespace ouzel;
using namespace ouzel::network;

void ouzel_luabinding_network(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::network::Network>();

	//Constructor
	metaTable.setConstructors<
		ouzel::network::Network()
	>();

	//PublicFunc
	metaTable.addFunction("init", &ouzel::network::Network::init);
	metaTable.addFunction("listen", &ouzel::network::Network::listen);
	metaTable.addFunction("connect", &ouzel::network::Network::connect);
	metaTable.addFunction("disconnect", &ouzel::network::Network::disconnect);

	//PublicStaticFunc
	metaTable.addStaticFunction("getLastError", &ouzel::network::Network::getLastError);
	metaTable.addStaticFunction("getAddress", &ouzel::network::Network::getAddress);

	state["oz"]["Network"].setClass(metaTable);
}
