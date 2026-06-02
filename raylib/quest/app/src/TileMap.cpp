#include "TileMap.h"

#include "Components/GridCellComponent.h"
#include "Components/ImageComponent.h"
#include "Components/LayerComponent.h"
#include "Components/MapDataComponent.h"
#include "Components/Transform2D.h"
#include "TileList.h"
#include "spdlog/spdlog.h"

TileMap TileMap::Create(gaia::ecs::World& world, const TileMapConfig& config)
{
    gaia::ecs::Entity rootEntity = world.add();

    const int32_t total = config.m_Column * config.m_Row;
    const TileList::Tile* defaultTile = TileList::Get(DEFAULT_TILE);

    MapDataComponent mapData;
    mapData.m_Column = config.m_Column;
    mapData.m_Row = config.m_Row;
    mapData.m_TileHeight = config.m_TileHeight;
    mapData.m_TileWidth = config.m_TileWidth;
    mapData.m_Tiles.resize((size_t)config.m_Column * config.m_Row);

    if (defaultTile == nullptr)
    {
        spdlog::error("Could not find a default tile to fill Tile Map with");
        return TileMap{gaia::ecs::EntityBad};
    }

    for (int i = 0; i < total; i++)
    {
        const uint32_t col = i % config.m_Column;
        const uint32_t row = i / config.m_Column;

        gaia::ecs::Entity tileEntity = world.add();

        ImageComponent imageComponent;
        imageComponent.m_Texture = defaultTile->m_Texture;
        imageComponent.m_SrcRect = defaultTile->m_SrcRect;

        world.add<ImageComponent>(tileEntity, std::move(imageComponent));
        world.add<GridCellComponent>(tileEntity, {col, row});

        world.add<Transform2D>(tileEntity, {col * defaultTile->m_SrcRect.width, row * defaultTile->m_SrcRect.height});
        world.add<LayerOneComponent>(tileEntity);

        mapData.m_Tiles[(size_t)i].push_back(tileEntity);
    }

    world.add<MapDataComponent>(rootEntity, std::move(mapData));

    return TileMap{rootEntity};
}