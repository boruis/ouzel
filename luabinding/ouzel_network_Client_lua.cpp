
#include "ouzel_network_Client_lua.hpp"

using namespace ouzel;
using namespace ouzel::network;

void ouzel_luabinding_client(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::network::Client>();

	//PublicFunc
	metaTable.addFunction("disconnect", &ouzel::network::Client::disconnect);

	state["oz"]["Client"].setClass(metaTable);
}
