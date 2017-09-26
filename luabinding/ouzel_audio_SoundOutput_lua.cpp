
#include "ouzel_audio_SoundOutput_lua.hpp"

using namespace ouzel;
using namespace ouzel::audio;

void ouzel_luabinding_soundoutput(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::audio::SoundOutput>();

	state["oz"]["SoundOutput"].setClass(metaTable);
}
