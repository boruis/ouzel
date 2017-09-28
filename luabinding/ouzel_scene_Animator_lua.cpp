
#include "ouzel_scene_Animator_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_animator(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Animator>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Animator(float aLength)
	>();

	//PublicFunc
	metaTable.addFunction("update", &ouzel::scene::Animator::update);
	metaTable.addFunction("start", &ouzel::scene::Animator::start);
	metaTable.addFunction("play", &ouzel::scene::Animator::play);
	metaTable.addFunction("resume", &ouzel::scene::Animator::resume);
	metaTable.addFunction("stop", &ouzel::scene::Animator::stop);
	metaTable.addFunction("reset", &ouzel::scene::Animator::reset);
	metaTable.addFunction("isRunning", &ouzel::scene::Animator::isRunning);
	metaTable.addFunction("isDone", &ouzel::scene::Animator::isDone);
	metaTable.addFunction("getLength", &ouzel::scene::Animator::getLength);
	metaTable.addFunction("getCurrentTime", &ouzel::scene::Animator::getCurrentTime);
	metaTable.addFunction("getProgress", &ouzel::scene::Animator::getProgress);
	metaTable.addFunction("setProgress", &ouzel::scene::Animator::setProgress);
	metaTable.addFunction("getTargetActor", &ouzel::scene::Animator::getTargetActor);
	metaTable.addFunction("removeAllAnimators", &ouzel::scene::Animator::removeAllAnimators);
	metaTable.addFunction("getParent", &ouzel::scene::Animator::getParent);
	metaTable.addFunction("removeFromParent", &ouzel::scene::Animator::removeFromParent);

	//Overloaded funcs
	auto addAnimatorPtr1 = static_cast<void(ouzel::scene::Animator::*)(Animator *animator)>(&ouzel::scene::Animator::addAnimator);
	metaTable.addOverloadedFunctions("addAnimator", addAnimatorPtr1);

	auto removeAnimatorPtr1 = static_cast<bool(ouzel::scene::Animator::*)(Animator *animator)>(&ouzel::scene::Animator::removeAnimator);
	metaTable.addOverloadedFunctions("removeAnimator", removeAnimatorPtr1);


	state["oz"]["Animator"].setClass(metaTable);
}
