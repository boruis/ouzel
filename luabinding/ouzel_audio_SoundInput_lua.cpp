
#include "ouzel_audio_SoundInput_lua.hpp"

using namespace ouzel;
using namespace ouzel::audio;

void ouzel_luabinding_soundinput(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::audio::SoundInput>();

	//PublicFunc
	metaTable.addFunction("getOutput", &ouzel::audio::SoundInput::getOutput);
	metaTable.addFunction("setOutput", &ouzel::audio::SoundInput::setOutput);
	metaTable.addFunction("addRenderCommands", &ouzel::audio::SoundInput::addRenderCommands);

	state["oz"]["SoundInput"].setClass(metaTable);
}
