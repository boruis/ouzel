
#include "ouzel_audio_SoundData_lua.hpp"

using namespace ouzel;
using namespace ouzel::audio;

void ouzel_luabinding_sounddata(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::audio::SoundData>();

	//Constructor
	metaTable.setConstructors<
		ouzel::audio::SoundData()
	>();

	//PublicFunc
	metaTable.addFunction("createStream", &ouzel::audio::SoundData::createStream);
	metaTable.addFunction("getData", &ouzel::audio::SoundData::getData);
	metaTable.addFunction("getChannels", &ouzel::audio::SoundData::getChannels);
	metaTable.addFunction("getSampleRate", &ouzel::audio::SoundData::getSampleRate);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::audio::SoundData::*)(const std::string &newFilename)>(&ouzel::audio::SoundData::init);
	auto initPtr2 = static_cast<bool(ouzel::audio::SoundData::*)(const std::vector< uint8_t > &newData)>(&ouzel::audio::SoundData::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2);


	state["oz"]["SoundData"].setClass(metaTable);
}
