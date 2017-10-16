
#include "ouzel_audio_Sound_lua.hpp"

using namespace ouzel;
using namespace ouzel::audio;

void ouzel_luabinding_sound(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::audio::Sound, ouzel::audio::SoundInput>();

	//Constructor
	metaTable.setConstructors<
		ouzel::audio::Sound()
	>();

	//PublicFunc
	metaTable.addFunction("init", &ouzel::audio::Sound::init);
	metaTable.addFunction("getSoundData", &ouzel::audio::Sound::getSoundData);
	metaTable.addFunction("getPosition", &ouzel::audio::Sound::getPosition);
	metaTable.addFunction("setPosition", &ouzel::audio::Sound::setPosition);
	metaTable.addFunction("getPitch", &ouzel::audio::Sound::getPitch);
	metaTable.addFunction("setPitch", &ouzel::audio::Sound::setPitch);
	metaTable.addFunction("getGain", &ouzel::audio::Sound::getGain);
	metaTable.addFunction("setGain", &ouzel::audio::Sound::setGain);
	metaTable.addFunction("getRolloffFactor", &ouzel::audio::Sound::getRolloffFactor);
	metaTable.addFunction("setRolloffFactor", &ouzel::audio::Sound::setRolloffFactor);
	metaTable.addFunction("getMinDistance", &ouzel::audio::Sound::getMinDistance);
	metaTable.addFunction("setMinDistance", &ouzel::audio::Sound::setMinDistance);
	metaTable.addFunction("getMaxDistance", &ouzel::audio::Sound::getMaxDistance);
	metaTable.addFunction("setMaxDistance", &ouzel::audio::Sound::setMaxDistance);
	metaTable.addFunction("isSpatialized", &ouzel::audio::Sound::isSpatialized);
	metaTable.addFunction("setSpatialized", &ouzel::audio::Sound::setSpatialized);
	metaTable.addFunction("play", &ouzel::audio::Sound::play);
	metaTable.addFunction("pause", &ouzel::audio::Sound::pause);
	metaTable.addFunction("stop", &ouzel::audio::Sound::stop);
	metaTable.addFunction("isPlaying", &ouzel::audio::Sound::isPlaying);
	metaTable.addFunction("isRepeating", &ouzel::audio::Sound::isRepeating);
	metaTable.addFunction("addRenderCommands", &ouzel::audio::Sound::addRenderCommands);

	state["oz"]["Sound"].setClass(metaTable);
}
