
#include "ouzel_scene_Ease_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_ease(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Ease, kaguya::MultipleBase<ouzel::scene::Animator, ouzel::scene::Component, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Ease(Animator *animator, ouzel::scene::Ease::Type aType, ouzel::scene::Ease::Func aFunc)
	>();

	state["oz"]["Ease"].setClass(metaTable);
}
