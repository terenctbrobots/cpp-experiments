#include "Hash.h"

uint32_t Hash_fnv1a(const std::string& s) 
{
    uint32_t h = 2166136261u;
    for (unsigned char c : s) 
    {
        h ^= c;
        h *= 16777619u;
    }
    return h;
}