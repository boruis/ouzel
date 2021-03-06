// Copyright (C) 2017 Elviss Strazdins
// This file is part of the Ouzel engine.

#include "WindowAndroid.hpp"
#include "EngineAndroid.hpp"
#include "utils/Log.hpp"

namespace ouzel
{
    WindowAndroid::WindowAndroid()
    {
    }

    WindowAndroid::~WindowAndroid()
    {
        if (window) ANativeWindow_release(window);
    }

    bool WindowAndroid::init(const Size2& newSize,
                             bool newResizable,
                             bool newFullscreen,
                             bool newExclusiveFullscreen,
                             const std::string& newTitle,
                             bool newHighDpi,
                             bool depth)
    {
        if (!Window::init(newSize,
                          newResizable,
                          newFullscreen,
                          newExclusiveFullscreen,
                          newTitle,
                          newHighDpi,
                          depth))
        {
            return false;
        }

        EngineAndroid* engineAndroid = static_cast<EngineAndroid*>(sharedEngine);
        JavaVM* javaVM = engineAndroid->getJavaVM();
        JNIEnv* jniEnv;

        if (javaVM->GetEnv(reinterpret_cast<void**>(&jniEnv), JNI_VERSION_1_6) != JNI_OK)
        {
            Log(Log::Level::ERR) << "Failed to get JNI environment";
            return false;
        }

        window = ANativeWindow_fromSurface(jniEnv, engineAndroid->getSurface());

        size.width = static_cast<float>(ANativeWindow_getWidth(window));
        size.height = static_cast<float>(ANativeWindow_getHeight(window));
        resolution = size;

        return true;
    }

    void WindowAndroid::handleResize(const Size2& newSize)
    {
        Event sizeChangeEvent;
        sizeChangeEvent.type = Event::Type::WINDOW_SIZE_CHANGE;
        sizeChangeEvent.windowEvent.window = this;
        sizeChangeEvent.windowEvent.size = newSize;
        sharedEngine->getEventDispatcher()->postEvent(sizeChangeEvent);

        Event resolutionChangeEvent;
        resolutionChangeEvent.type = Event::Type::RESOLUTION_CHANGE;
        resolutionChangeEvent.windowEvent.window = this;
        resolutionChangeEvent.windowEvent.size = newSize;
        sharedEngine->getEventDispatcher()->postEvent(resolutionChangeEvent);
    }

    void WindowAndroid::handleSurfaceChange(jobject surface)
    {
        EngineAndroid* engineAndroid = static_cast<EngineAndroid*>(sharedEngine);
        JavaVM* javaVM = engineAndroid->getJavaVM();
        JNIEnv* jniEnv;

        if (javaVM->GetEnv(reinterpret_cast<void**>(&jniEnv), JNI_VERSION_1_6) != JNI_OK)
        {
            Log(Log::Level::ERR) << "Failed to get JNI environment";
            return;
        }

        if (window) ANativeWindow_release(window);
        window = ANativeWindow_fromSurface(jniEnv, surface);
    }

    void WindowAndroid::handleSurfaceDestroy()
    {
        if (window)
        {
            ANativeWindow_release(window);
            window = nullptr;
        }
    }
}
