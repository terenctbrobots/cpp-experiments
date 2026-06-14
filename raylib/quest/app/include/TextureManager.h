#pragma once
#include "raylib.h"

#include <string>
#include <sys/types.h>

namespace TileList
{
    struct Tile;
}

namespace TextureManager
{
    enum class TextureType
    {
        Invalid,
        Sprite,
        TileSet
    };

    struct Texture
    {
        TextureType m_TextureType;
        std::string m_Path;
        std::string m_DataPath;
        Texture2D m_Texture;
    };

    bool Initialize();
    const Texture& Load(const std::string& key);
    //     Add(const std::string& texturePath, const Texture2D& newTexture2D, TextureType textureType);
    // const Texture2D* GetTexture(u_int32_t hash);
    // const u_int32_t GetHash(const Texture2D& checkTexture);
    void Clear();
    void Clear(TextureType textureType);
} // namespace TextureManager
