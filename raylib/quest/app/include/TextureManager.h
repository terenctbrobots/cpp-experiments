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
    const Texture2D& Get(const std::string& key);
    void Clear();
    void Clear(TextureType textureType);
} // namespace TextureManager
