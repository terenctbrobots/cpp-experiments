#include "TileMap.h"

#include "Components/GridCellComponent.h"
#include "Components/ImageComponent.h"
#include "Components/LayerComponent.h"
#include "Components/MapDataComponent.h"
#include "Components/Transform2D.h"
#include "TileList.h"
#include "spdlog/spdlog.h"

#include <fstream>
#include <nlohmann/json.hpp>

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
        imageComponent.m_TextureHash = defaultTile->m_TextureHash;
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

bool TileMap::IsValid()
{
    return (m_Root != gaia::ecs::EntityBad);
}

bool TileMap::Save(gaia::ecs::World& world, const std::string& fileName)
{
    if (!world.has<MapDataComponent>(m_Root))
    {
        spdlog::error("No root MapDataComponent");
        return false;
    }

    auto& mapDataComponent = world.get<MapDataComponent>(m_Root);

    nlohmann::json toJson;

    toJson["column"] = mapDataComponent.m_Column;
    toJson["row"] = mapDataComponent.m_Row;

    toJson["tiles"] = nlohmann::json::array();

    for (std::vector<gaia::ecs::Entity> tileEntityList : mapDataComponent.m_Tiles)
    {
        nlohmann::json tileArray = nlohmann::json::array();
        for (gaia::ecs::Entity tileEntity : tileEntityList)
        {
            nlohmann::json tile;
            auto& imageComponent = world.get<ImageComponent>(tileEntity);

            tile["texture_hash"] = imageComponent.m_TextureHash;

            tileArray.push_back(tile);
        }
        toJson["tiles"].push_back(tileArray);
    }

    std::ofstream file(fileName);
    if (!file)
    {
        spdlog::error("Cannot open {} file to write", fileName);
        return false;
    }

    file << toJson.dump(4); // Indent by 4
    return true;
}

bool TileMap::Load(gaia::ecs::World& world, const std::string& fileName)
{
    if (m_Root != gaia::ecs::EntityBad)
    {
        spdlog::error("Use and empty Tilemap or call Destroy before Loading");
        return false;
    }

    std::ifstream file(fileName);

    if (!file)
    {
        spdlog::error("Cannot read {} file", fileName);
        return false;
    }

    nlohmann::json fromJson;
    file >> fromJson;

    m_Root = world.add();
    MapDataComponent mapDataComponent;

    fromJson.at("column").get_to(mapDataComponent.m_Column);
    fromJson.at("row").get_to(mapDataComponent.m_Row);

    world.add<MapDataComponent>(m_Root, std::move(mapDataComponent));

    return true;
}

void TileMap::Destroy(gaia::ecs::World& world)
{
    if (m_Root == gaia::ecs::EntityBad)
    {
        spdlog::error("Nothing to destroy, root entity is already invalid");
        return;
    }

    world.del(m_Root);
    m_Root = gaia::ecs::EntityBad;
}