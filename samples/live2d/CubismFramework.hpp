#pragma once

#include "ouzel.hpp"
#include "../external/live2d/include/Live2DCubismCore.h"

using namespace ouzel;


// Cubism model.
typedef struct csmModel csmModel;

// ----- //
// TYPES //
// ----- //

/// 16-bit hash value.
typedef unsigned short csmHash;

/// Look up table.
typedef struct csmModelHashTable
{
    /// Parameters.
    std::vector<csmHash> Parameters;
    
    /// Parts.
    std::vector<csmHash> Parts;
} csmModelHashTable;


void alignVectorSize(std::vector<uint8_t> &data, uint dataSize, uint alignSize);

std::vector<uint8_t> ReadBlobAligned(const char* path, const unsigned int alignment, unsigned int* outSize);


csmHash csmHashId(const char* id);

csmHash csmHashIdFromSubString(const char* string, const int idBegin, const int idEnd);

//init hash table
void initModelHashTable(csmModelHashTable &hashTable, const csmModel* model);
