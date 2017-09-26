
#include "ouzel_scene_Repeat_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_repeat(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Repeat>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Repeat(Animator *animator, uint32_t aCount),
		ouzel::scene::Repeat(const std::unique_ptr< Animator > &animator, uint32_t aCount)
	>();

	//PublicFunc
	metaTable.addFunction("reset", &ouzel::scene::Repeat::reset);

	state["oz"]["Repeat"].setClass(metaTable);
}
