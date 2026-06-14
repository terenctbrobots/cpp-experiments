#pragma once

#include "raylib.h"

#include <gaia.h>

namespace TextureManager
{
    struct Texture;
};

namespace TileList
{
    struct Tile
    {
        std::string m_Name;
        Texture2D m_Texture;
        std::string m_TextureKey;
        Rectangle m_SrcRect;
    };

    bool LoadTileList();
    bool LoadTileSet(const std::string& textureKey, const TextureManager::Texture& texture);

    const Tile* Get(const u_int32_t tileId);
} // namespace TileList
