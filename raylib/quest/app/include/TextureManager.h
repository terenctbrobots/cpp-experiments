#pragma once
#include "raylib.h"

#include <cstdint>
#include <string>

namespace TextureManager
{
    bool Add(const std::string& texturePath, const Texture2D& newTexture);
    const Texture2D* GetTexture(u_int32_t hash);
    const u_int32_t GetHash(const Texture2D& checkTexture);
    void Clear();
} // namespace TextureManager