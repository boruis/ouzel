
#include "ouzel_audio_AudioDevice_lua.hpp"

using namespace ouzel;
using namespace ouzel::audio;

void ouzel_luabinding_audiodevice(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::audio::AudioDevice>();

	//PublicFunc
	metaTable.addFunction("process", &ouzel::audio::AudioDevice::process);
	metaTable.addFunction("getAPIMajorVersion", &ouzel::audio::AudioDevice::getAPIMajorVersion);
	metaTable.addFunction("getAPIMinorVersion", &ouzel::audio::AudioDevice::getAPIMinorVersion);
	metaTable.addFunction("executeOnAudioThread", &ouzel::audio::AudioDevice::executeOnAudioThread);
	metaTable.addFunction("setRenderCommands", &ouzel::audio::AudioDevice::setRenderCommands);

	state["oz"]["AudioDevice"].setClass(metaTable);
}
