#pragma once
#include "raylib.h"

#include <cstdint>
#include <string>

namespace TextureManager
{
    enum class TextureType
    {
        Character,
        TileList
    };

    struct Texture
    {
        std::string m_Path;
        Texture2D m_Texture;
        TextureType m_TextureType;
    };

    u_int32_t Add(const std::string& texturePath, const Texture2D& newTexture2D, TextureType textureType);
    const Texture2D* GetTexture(u_int32_t hash);
    const u_int32_t GetHash(const Texture2D& checkTexture);
    void Clear();
    void Clear(TextureType textureType);
} // namespace TextureManager