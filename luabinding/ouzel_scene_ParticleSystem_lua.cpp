
#include "ouzel_scene_ParticleSystem_lua.hpp"

using namespace ouzel;
using namespace ouzel::scene;

void ouzel_luabinding_particlesystem(kaguya::State &state)
{
	auto metaTable = kaguya::UserdataMetatable<ouzel::scene::ParticleSystem, kaguya::MultipleBase<ouzel::scene::Component, ouzel::Noncopyable> >();

	//Constructor
	metaTable.setConstructors<
		ouzel::scene::ParticleSystem(),
		ouzel::scene::ParticleSystem(const std::string &filename)
	>();

	//PublicFunc
	metaTable.addFunction("draw", &ouzel::scene::ParticleSystem::draw);
	metaTable.addFunction("resume", &ouzel::scene::ParticleSystem::resume);
	metaTable.addFunction("stop", &ouzel::scene::ParticleSystem::stop);
	metaTable.addFunction("reset", &ouzel::scene::ParticleSystem::reset);
	metaTable.addFunction("isRunning", &ouzel::scene::ParticleSystem::isRunning);
	metaTable.addFunction("isActive", &ouzel::scene::ParticleSystem::isActive);
	metaTable.addFunction("setPositionType", &ouzel::scene::ParticleSystem::setPositionType);
	metaTable.addFunction("getPositionType", &ouzel::scene::ParticleSystem::getPositionType);

	//Overloaded funcs
	auto initPtr1 = static_cast<bool(ouzel::scene::ParticleSystem::*)(const ParticleDefinition &newParticleDefinition)>(&ouzel::scene::ParticleSystem::init);
	auto initPtr2 = static_cast<bool(ouzel::scene::ParticleSystem::*)(const std::string &filename)>(&ouzel::scene::ParticleSystem::init);
	metaTable.addOverloadedFunctions("init", initPtr1, initPtr2);


	state["oz"]["ParticleSystem"].setClass(metaTable);
}
