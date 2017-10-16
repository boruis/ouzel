
#include "ouzel_scene_Parallel_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_parallel(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Parallel, kaguya::MultipleBase<ouzel::scene::Animator, ouzel::scene::Component, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Parallel(const std::vector< Animator *> &aAnimators)
	>();

	state["oz"]["Parallel"].setClass(metaTable);
}
