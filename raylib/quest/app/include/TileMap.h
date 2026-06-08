#pragma once

#include "Hash.h"
#include "raylib.h"

#include <gaia.h>
#include <string>

struct TileMapConfig
{
    std::string m_Name;
    int m_Column;
    int m_Row;
    float m_TileWidth;
    float m_TileHeight;
};

const u_int32_t DEFAULT_TILE = HS("ground");

class TileMap
{
    public:
    TileMap() : m_Root(gaia::ecs::EntityBad)
    {
    }
    explicit TileMap(gaia::ecs::Entity root) : m_Root(root)
    {
    }
    static TileMap Create(gaia::ecs::World& world, const TileMapConfig& config);

    bool Save(gaia::ecs::World& world, const std::string& fileName);
    bool Load(gaia::ecs::World& world, const std::string& fileName);
    bool IsValid();
    void Destroy(gaia::ecs::World& world);

    private:
    gaia::ecs::Entity m_Root;
};
