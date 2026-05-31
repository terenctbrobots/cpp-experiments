#pragma once

#include <gaia.h>
#include "raylib.h"

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
}