
#include "ouzel_scene_Ease_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_ease(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Ease>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Ease(Animator *animator, Type aType, Func aFunc),
		ouzel::scene::Ease(const std::unique_ptr< Animator > &animator, Type aType, Func aFunc)
	>();

	state["oz"]["Ease"].setClass(metaTable);
}
