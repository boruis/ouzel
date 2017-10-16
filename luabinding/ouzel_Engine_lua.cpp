
#include "ouzel_Engine_lua.hpp"

using namespace ouzel;

void ouzel_luabinding_engine(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::Engine, ouzel::Noncopyable>();

	//Constructor
	metaTable.setConstructors<
		ouzel::Engine()
	>();

	//PublicFunc
	metaTable.addFunction("init", &ouzel::Engine::init);
	metaTable.addFunction("getArgs", &ouzel::Engine::getArgs);
	metaTable.addFunction("getFileSystem", &ouzel::Engine::getFileSystem);
	metaTable.addFunction("getEventDispatcher", &ouzel::Engine::getEventDispatcher);
	metaTable.addFunction("getTimer", &ouzel::Engine::getTimer);
	metaTable.addFunction("getCache", &ouzel::Engine::getCache);
	metaTable.addFunction("getWindow", &ouzel::Engine::getWindow);
	metaTable.addFunction("getRenderer", &ouzel::Engine::getRenderer);
	metaTable.addFunction("getAudio", &ouzel::Engine::getAudio);
	metaTable.addFunction("getSceneManager", &ouzel::Engine::getSceneManager);
	metaTable.addFunction("getInput", &ouzel::Engine::getInput);
	metaTable.addFunction("getLocalization", &ouzel::Engine::getLocalization);
	metaTable.addFunction("getNetwork", &ouzel::Engine::getNetwork);
	metaTable.addFunction("getDefaultSettings", &ouzel::Engine::getDefaultSettings);
	metaTable.addFunction("getUserSettings", &ouzel::Engine::getUserSettings);
	metaTable.addFunction("run", &ouzel::Engine::run);
	metaTable.addFunction("start", &ouzel::Engine::start);
	metaTable.addFunction("pause", &ouzel::Engine::pause);
	metaTable.addFunction("resume", &ouzel::Engine::resume);
	metaTable.addFunction("exit", &ouzel::Engine::exit);
	metaTable.addFunction("isPaused", &ouzel::Engine::isPaused);
	metaTable.addFunction("isActive", &ouzel::Engine::isActive);
	metaTable.addFunction("scheduleUpdate", &ouzel::Engine::scheduleUpdate);
	metaTable.addFunction("unscheduleUpdate", &ouzel::Engine::unscheduleUpdate);
	metaTable.addFunction("update", &ouzel::Engine::update);
	metaTable.addFunction("executeOnMainThread", &ouzel::Engine::executeOnMainThread);
	metaTable.addFunction("openURL", &ouzel::Engine::openURL);
	metaTable.addFunction("setScreenSaverEnabled", &ouzel::Engine::setScreenSaverEnabled);
	metaTable.addFunction("isScreenSaverEnabled", &ouzel::Engine::isScreenSaverEnabled);
	metaTable.addFunction("setCurrentThreadName", &ouzel::Engine::setCurrentThreadName);

	state["oz"]["Engine"].setClass(metaTable);
}
