// Copyright (C) 2017 Elviss Strazdins
// This file is part of the Ouzel engine.

#pragma once

class GUISample: public ouzel::scene::Scene
{
public:
    GUISample();

private:
    bool handleGamepad(ouzel::Event::Type type, const ouzel::GamepadEvent& event);
    bool handleUI(ouzel::Event::Type type, const ouzel::UIEvent& event);
    bool handleKeyboard(ouzel::Event::Type type, const ouzel::KeyboardEvent& event) const;

    ouzel::EventHandler eventHandler;

    ouzel::gui::Button button;
    ouzel::gui::Button fullscreenButton;
    ouzel::gui::CheckBox checkBox;

    ouzel::gui::Label label1;
    ouzel::gui::Label label2;
    ouzel::gui::Label label3;

    ouzel::scene::Layer guiLayer;
    ouzel::scene::Camera guiCamera;
    ouzel::gui::Menu menu;
    ouzel::gui::Button backButton;
    
    ouzel::scene::Actor live2dActor;
};
