
#include "ouzel_audio_Listener_lua.hpp"

using namespace ouzel;
using namespace ouzel::audio;

void ouzel_luabinding_listener(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::audio::Listener, ouzel::audio::SoundOutput>();

	//Constructor
	metaTable.setConstructors<
		ouzel::audio::Listener()
	>();

	//PublicFunc
	metaTable.addFunction("getPosition", &ouzel::audio::Listener::getPosition);
	metaTable.addFunction("setPosition", &ouzel::audio::Listener::setPosition);
	metaTable.addFunction("getRotation", &ouzel::audio::Listener::getRotation);
	metaTable.addFunction("setRotation", &ouzel::audio::Listener::setRotation);
	metaTable.addFunction("getRenderCommand", &ouzel::audio::Listener::getRenderCommand);

	state["oz"]["Listener"].setClass(metaTable);
}
