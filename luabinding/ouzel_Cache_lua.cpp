
#include "ouzel_Cache_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_cache(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Cache>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Cache()
	>();

	//PublicFunc
	metaTable.addFunction("clear", &ouzel::Cache::clear);
	metaTable.addFunction("preloadTexture", &ouzel::Cache::preloadTexture);
	metaTable.addFunction("getTexture", &ouzel::Cache::getTexture);
	metaTable.addFunction("setTexture", &ouzel::Cache::setTexture);
	metaTable.addFunction("releaseTextures", &ouzel::Cache::releaseTextures);
	metaTable.addFunction("getShader", &ouzel::Cache::getShader);
	metaTable.addFunction("setShader", &ouzel::Cache::setShader);
	metaTable.addFunction("releaseShaders", &ouzel::Cache::releaseShaders);
	metaTable.addFunction("getBlendState", &ouzel::Cache::getBlendState);
	metaTable.addFunction("setBlendState", &ouzel::Cache::setBlendState);
	metaTable.addFunction("releaseBlendStates", &ouzel::Cache::releaseBlendStates);
	metaTable.addFunction("preloadSpriteDefinition", &ouzel::Cache::preloadSpriteDefinition);
	metaTable.addFunction("getSpriteDefinition", &ouzel::Cache::getSpriteDefinition);
	metaTable.addFunction("setSpriteDefinition", &ouzel::Cache::setSpriteDefinition);
	metaTable.addFunction("releaseSpriteDefinitions", &ouzel::Cache::releaseSpriteDefinitions);
	metaTable.addFunction("preloadParticleDefinition", &ouzel::Cache::preloadParticleDefinition);
	metaTable.addFunction("getParticleDefinition", &ouzel::Cache::getParticleDefinition);
	metaTable.addFunction("setParticleDefinition", &ouzel::Cache::setParticleDefinition);
	metaTable.addFunction("releaseParticleDefinitions", &ouzel::Cache::releaseParticleDefinitions);
	metaTable.addFunction("preloadFont", &ouzel::Cache::preloadFont);
	metaTable.addFunction("getFont", &ouzel::Cache::getFont);
	metaTable.addFunction("setFont", &ouzel::Cache::setFont);
	metaTable.addFunction("releaseFonts", &ouzel::Cache::releaseFonts);
	metaTable.addFunction("preloadSoundData", &ouzel::Cache::preloadSoundData);
	metaTable.addFunction("getSoundData", &ouzel::Cache::getSoundData);
	metaTable.addFunction("setSoundData", &ouzel::Cache::setSoundData);
	metaTable.addFunction("releaseSoundData", &ouzel::Cache::releaseSoundData);

	state["oz"]["Cache"].setClass(metaTable);
}
