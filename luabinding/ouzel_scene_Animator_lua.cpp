
#include "ouzel_scene_Animator_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

template <typename T>
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
	auto addAnimatorPtr2 = static_cast<void(ouzel::scene::Animator::*)(const std::unique_ptr< T > &animator)>(&ouzel::scene::Animator::addAnimator);
	auto addAnimatorPtr3 = static_cast<void(ouzel::scene::Animator::*)(std::unique_ptr< T > &&animator)>(&ouzel::scene::Animator::addAnimator);
	metaTable.addOverloadedFunctions("addAnimator", addAnimatorPtr1, addAnimatorPtr2, addAnimatorPtr3);

	auto removeAnimatorPtr1 = static_cast<bool(ouzel::scene::Animator::*)(Animator *animator)>(&ouzel::scene::Animator::removeAnimator);
	auto removeAnimatorPtr2 = static_cast<bool(ouzel::scene::Animator::*)(const std::unique_ptr< T > &animator)>(&ouzel::scene::Animator::removeAnimator);
	metaTable.addOverloadedFunctions("removeAnimator", removeAnimatorPtr1, removeAnimatorPtr2);


	state["oz"]["Animator"].setClass(metaTable);
}
