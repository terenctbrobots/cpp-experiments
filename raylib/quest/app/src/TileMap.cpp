#include "TileMap.h"

#include "Components/MapDataComponent.h"

TileMap TileMap::Create(gaia::ecs::World& world, const TileMapConfig& config)
{

    gaia::ecs::Entity rootEntity = world.add();

    const int32_t total = config.m_Column * config.m_Row;

    for (int i = 0; i < total; i++)
    {
        const int32_t col = i % config.m_Column;
        const int32_t row = i / config.m_Column;

        gaia::ecs::Entity tileEntity = world.add();
    }

    return TileMap{rootEntity};
}