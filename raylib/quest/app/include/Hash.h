#pragma once
#include <string>
#include <cstdint>

uint32_t Hash_fnv1a(const std::string& s);

#define HS(string) Hash_fnv1a(string)
