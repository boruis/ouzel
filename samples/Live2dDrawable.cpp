//
//  Live2dDrawable.cpp
//  samples
//
//  Created by john on 2017/9/26.
//  Copyright © 2017年 Elviss Strazdins. All rights reserved.
//

#include "Live2dDrawable.hpp"

namespace live2d {
    
    Live2dDrawable::Live2dDrawable():Component(TYPE)
    {
        mocMemory = ReadBlobAligned("Koharu/Koharu.moc3", csmAlignofMoc, &mocSize);
        
        Moc = csmReviveMocInPlace(mocMemory.data(), mocSize);
        
        // Instantiate moc.
        modelSize = csmGetSizeofModel(Moc);
        alignVectorSize(modelMemory, modelSize, csmAlignofModel);

        Model = csmInitializeModelInPlace(Moc, modelMemory.data(), modelSize);

        // init hash table.
        initModelHashTable(hashTable, Model);
    }
    
    Live2dDrawable::~Live2dDrawable()
    {
        
    }

}
