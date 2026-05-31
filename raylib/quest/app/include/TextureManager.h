#pragma once
#include "raylib.h"

namespace TextureManager
{
    bool Add(Texture2D& newTexture);
    bool Remove(Texture2D& oldTexture);
    void Clear();
}