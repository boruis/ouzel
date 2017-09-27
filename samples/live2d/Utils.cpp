//
//  Utils.cpp
//  samples
//
//  Created by john on 2017/9/26.
//  Copyright © 2017年 Elviss Strazdins. All rights reserved.
//

#include "Utils.hpp"


int GetStringLength(const char* string, const int iterations)
{
    int c;
    
    for (c = 0; c < iterations && string[c] != '\0'; ++c)
    {
        ;
    }
    
    return c;
}
