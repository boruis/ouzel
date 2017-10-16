
#include "ouzel_audio_Mixer_lua.hpp"

using namespace ouzel;
using namespace ouzel::audio;

void ouzel_luabinding_mixer(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::audio::Mixer, ouzel::Noncopyable>();

	//Constructor
	metaTable.setConstructors<
		ouzel::audio::Mixer()
	>();

	//PublicFunc
	metaTable.addFunction("getPitch", &ouzel::audio::Mixer::getPitch);
	metaTable.addFunction("setPitch", &ouzel::audio::Mixer::setPitch);
	metaTable.addFunction("getGain", &ouzel::audio::Mixer::getGain);
	metaTable.addFunction("setGain", &ouzel::audio::Mixer::setGain);
	metaTable.addFunction("getRolloffScale", &ouzel::audio::Mixer::getRolloffScale);
	metaTable.addFunction("setRolloffScale", &ouzel::audio::Mixer::setRolloffScale);
	metaTable.addFunction("addRenderCommands", &ouzel::audio::Mixer::addRenderCommands);

	state["oz"]["Mixer"].setClass(metaTable);
}
