// Copyright (C) 2017 Elviss Strazdins
// This file is part of the Ouzel engine.

#include <unistd.h>
#include <pwd.h>
#include <Foundation/Foundation.h>
#include "FileSystemIOS.h"

static char TEMP_BUFFER[1024];

namespace ouzel
{
    FileSystemIOS::FileSystemIOS()
    {
        NSBundle* bundle = [NSBundle mainBundle];
        NSString* path = [bundle resourcePath];

        appPath = [path UTF8String];
    }

    std::string FileSystemIOS::getHomeDirectory() const
    {
        return "";
    }

    std::string FileSystemIOS::getStorageDirectory(bool user) const
    {
        NSArray* paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, user ? NSUserDomainMask : NSLocalDomainMask, YES);
        NSString* documentsDirectory = [paths objectAtIndex:0];

        return [documentsDirectory UTF8String];
    }

    std::string FileSystemIOS::getTempDirectory() const
    {
        if (confstr(_CS_DARWIN_USER_TEMP_DIR, TEMP_BUFFER, sizeof(TEMP_BUFFER)))
        {
            return TEMP_BUFFER;
        }
        else
        {
            char const* path = getenv("TMPDIR");
            if (path)
            {
                return path;
            }
            else
            {
                return "/tmp";
            }
        }
    }
}