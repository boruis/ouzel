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

void ouzelMain(const std::vector<std::string>& args)
{
    // disable screen saver
    ouzel::sharedEngine->setScreenSaverEnabled(false);

    std::string sample;

    for (auto arg = args.begin(); arg != args.end(); ++arg)
    {
        if (arg == args.begin())
        {
            // skip the first parameter
            continue;
        }

        if (*arg == "-sample")
        {
            auto nextArg = ++arg;

            if (nextArg != args.end())
            {
                sample = *nextArg;
            }
            else
            {
                ouzel::Log(ouzel::Log::Level::WARN) << "No sample specified";
            }
        }
        else
        {
            ouzel::Log(ouzel::Log::Level::WARN) << "Invalid argument \"" << *arg << "\"";
        }
    }

    ouzel::sharedEngine->getFileSystem()->addResourcePath("Resources");

    ouzel::sharedEngine->getRenderer()->setClearColor(ouzel::Color(64, 0, 0));

    std::unique_ptr<ouzel::scene::Scene> currentScene;

    if (!sample.empty())
    {
        if (sample == "sprites")
        {
            currentScene.reset(new SpritesSample());
        }
        else if (sample == "gui")
        {
            currentScene.reset(new GUISample());
        }
        else if (sample == "render_target")
        {
            currentScene.reset(new RTSample());
        }
        else if (sample == "animations")
        {
            currentScene.reset(new AnimationsSample());
        }
        else if (sample == "input")
        {
            currentScene.reset(new InputSample());
        }
        else if (sample == "sound")
        {
            currentScene.reset(new SoundSample());
        }
        else if (sample == "perspective")
        {
            currentScene.reset(new PerspectiveSample());
        }
    }
    
    if (!currentScene)
    {
        currentScene.reset(new MainMenu());
    }
    
    // lua binding
    kaguya::State state;
    state["oz"] = kaguya::NewTable();
    state["oz"]["sharedEngine"] = static_cast<ouzel::Engine *>(ouzel::sharedEngine);
    
    ouzel_luabinding_all(state);
    
    // load dump
    auto dumpPath = ouzel::sharedEngine->getFileSystem()->getPath("dump.lua");
    state.dofile(dumpPath);

    auto fullPath = ouzel::sharedEngine->getFileSystem()->getPath("test.lua");
    state.dofile(fullPath);

    ouzel::sharedEngine->getSceneManager()->setScene(std::move(currentScene));
}
