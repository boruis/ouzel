#include "CubismFramework.hpp"
#include "Utils.hpp"

void alignVectorSize(std::vector<uint8_t> &data, uint dataSize, uint alignSize){
    uint alienedSize = dataSize + dataSize % alignSize;
    data.resize(alienedSize);
}

std::vector<uint8_t> ReadBlobAligned(const char* path, const unsigned int alignment, unsigned int* outSize)
{
    std::vector<uint8_t> newData;
    if (!sharedEngine->getFileSystem()->readFile(path, newData))
    {
        return newData;
    }
    
    // Store size.
    if (outSize)
    {
        (*outSize) = (uint)newData.size();
    }
    
    // align memory
    alignVectorSize(newData, (uint)newData.size(), alignment);
    
    return newData;
}

// -------------- //
// IMPLEMENTATION //
// -------------- //

csmHash csmHashId(const char* id)
{
    return csmHashIdFromSubString(id, 0, GetStringLength(id, 64));
}

// INV  Is algorithm sufficient for its purpose?
csmHash csmHashIdFromSubString(const char* string, const int idBegin, const int idEnd)
{
    csmHash hash;
    int c;
    
    for (hash = 0, c = idBegin; c < idEnd; ++c)
    {
        hash = (hash * 13) + (unsigned char)string[c];
    }
    
    return hash;
}


void initModelHashTable(csmModelHashTable &hashTable, const csmModel* model)
{
    int i;
    // Initialize parameters.
    int parameterCount = csmGetParameterCount(model);
    for (i = 0; i < parameterCount; ++i)
    {
        hashTable.Parameters.push_back(csmHashId(csmGetParameterIds(model)[i]));
    }
    
    // Initialize parts.
    int partsCount =  csmGetPartCount(model);
    for (i = 0; i < partsCount; ++i)
    {
        hashTable.Parts.push_back(csmHashId(csmGetPartIds(model)[i]));
    }
}

