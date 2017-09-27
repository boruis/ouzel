//
//  Live2dDrawable.hpp
//  samples
//
//  Created by john on 2017/9/26.
//  Copyright © 2017年 Elviss Strazdins. All rights reserved.
//

#ifndef Live2dDrawable_hpp
#define Live2dDrawable_hpp

#include "ouzel.hpp"
#include "../external/live2d/include/Live2DCubismCore.h"
#include "live2d/CubismFramework.hpp"

using namespace ouzel;

namespace live2d {
    
    class Live2dDrawable: public ouzel::scene::Component
    {
    public:
        static const uint32_t TYPE = 0x5350494e; // SPIN

        Live2dDrawable();
        
        ~Live2dDrawable();
        
    private:
        
        unsigned int mocSize, modelSize, tableSize;
        
        std::vector<uint8_t> mocMemory, modelMemory, tableMemory;
        
        csmMoc* Moc;
        
        csmModel* Model;
        
        csmModelHashTable hashTable;
    };
}

#endif /* Live2dDrawable_hpp */
