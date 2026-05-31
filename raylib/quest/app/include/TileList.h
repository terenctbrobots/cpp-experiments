#pragma once

#include "raylib.h"

#include <gaia.h>

namespace TileList
{
    struct Tile
    {
        std::string m_Name;
        Texture2D m_Texture;
        Rectangle m_SrcRect;
    };

    bool LoadTileList();
    bool LoadTileSet(const std::string& tileSetFilename, const std::string& textureFilename);

    const Tile* Get(const u_int32_t tileId);
} // namespace TileList