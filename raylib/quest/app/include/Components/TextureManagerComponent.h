#pragma once

#include "raylib.h"
#include <unordered_map>

struct TextureManagerComponent
{
    std::unordered_map<unsigned int, Texture2D> m_TextureList;
};