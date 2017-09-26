
#include "ouzel_audio_SoundDataWave_lua.hpp"

using namespace ouzel;
using namespace ouzel::audio;

void ouzel_luabinding_sounddatawave(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::audio::SoundDataWave>();

	//Constructor
	metaTable.setConstructors<
		ouzel::audio::SoundDataWave()
	>();

	//PublicFunc
	metaTable.addFunction("createStream", &ouzel::audio::SoundDataWave::createStream);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::audio::SoundDataWave::*)(const std::string &newFilename) override>(&ouzel::audio::SoundDataWave::init);
	auto initPtr2 = static_cast<bool(ouzel::audio::SoundDataWave::*)(const std::vector< uint8_t > &newData) override>(&ouzel::audio::SoundDataWave::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2);


	state["oz"]["SoundDataWave"].setClass(metaTable);
}
