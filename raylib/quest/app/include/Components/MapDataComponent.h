#pragma once

#include <gaia.h>
#include <vector>

struct MapDataComponent
{
    int m_Column;
    int m_Row;
    float m_TileWidth;
    float m_TileHeight;

    std::vector<std::vector<gaia::ecs::Entity>> m_Tiles;
};