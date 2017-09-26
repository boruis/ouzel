
#include "ouzel_scene_Parallel_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_parallel(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Parallel>();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Parallel(const std::vector< Animator *> &aAnimators),
		ouzel::scene::Parallel(const std::vector< std::unique_ptr< Animator >> &aAnimators)
	>();

	state["oz"]["Parallel"].setClass(metaTable);
}
