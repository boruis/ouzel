
#include "ouzel_scene_Sequence_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_sequence(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::Sequence, kaguya::MultipleBase<ouzel::scene::Animator, ouzel::scene::Component, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::Sequence(const std::vector< Animator *> &aAnimators)
	>();

	//PublicFunc
	metaTable.addFunction("play", &ouzel::scene::Sequence::play);

	state["oz"]["Sequence"].setClass(metaTable);
}
