// Copyright (C) 2017 Elviss Strazdins
// This file is part of the Ouzel engine.

#include "MainMenu.hpp"
#include "SpritesSample.hpp"
#include "GUISample.hpp"
#include "RTSample.hpp"
#include "AnimationsSample.hpp"
#include "InputSample.hpp"
#include "SoundSample.hpp"
#include "PerspectiveSample.hpp"

#include "ouzel_lua.hpp"

std::string DEVELOPER_NAME = "org.ouzelengine";
std::string APPLICATION_NAME = "samples";

kaguya::State state;

void ouzelMain(const std::vector<std::string>& args)
{
    // disable screen saver
    ouzel::sharedEngine->setScreenSaverEnabled(false);

    std::string sample;

    ouzel::sharedEngine->getFileSystem()->addResourcePath("Resources");

    ouzel::sharedEngine->getRenderer()->setClearColor(ouzel::Color(64, 0, 0));
//    ouzel::sharedEngine->getSceneManager()->setScene(new GUISample());
    
    // lua binding
    state["oz"] = kaguya::NewTable();
    
    ouzel_luabinding_all(state);

    state["oz"]["sharedEngine"] = ouzel::sharedEngine;

    state["tmpcamera"] = new ouzel::scene::Camera();
    
    // load dump
    auto dumpPath = ouzel::sharedEngine->getFileSystem()->getPath("dump.lua");
    state.dofile(dumpPath);

    auto fullPath = ouzel::sharedEngine->getFileSystem()->getPath("test.lua");
    state.dofile(fullPath);
}
