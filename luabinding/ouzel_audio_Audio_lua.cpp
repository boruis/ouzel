
#include "ouzel_audio_Audio_lua.hpp"

using namespace ouzel;
using namespace ouzel::audio;

void ouzel_luabinding_audio(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::audio::Audio>();

	//PublicFunc
	metaTable.addFunction("getDevice", &ouzel::audio::Audio::getDevice);
	metaTable.addFunction("update", &ouzel::audio::Audio::update);
	metaTable.addFunction("executeOnAudioThread", &ouzel::audio::Audio::executeOnAudioThread);
	metaTable.addFunction("addListener", &ouzel::audio::Audio::addListener);
	metaTable.addFunction("removeListener", &ouzel::audio::Audio::removeListener);

	//PublicStaticFunc
	metaTable.addStaticFunction("getAvailableAudioDrivers", &ouzel::audio::Audio::getAvailableAudioDrivers);
	metaTable.addStaticFunction("resampleLerp", &ouzel::audio::Audio::resampleLerp);

	state["oz"]["Audio"].setClass(metaTable);
}
