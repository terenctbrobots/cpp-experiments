#include "TileMap.h"

#include "Components/GridCellComponent.h"
#include "Components/ImageComponent.h"
#include "Components/LayerComponent.h"
#include "Components/MapDataComponent.h"
#include "Components/Transform2D.h"
#include "TileList.h"
#include "spdlog/spdlog.h"
#include "TextureManager.h"

#include <fstream>
#include <nlohmann/json.hpp>
#include <sys/types.h>

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
            tile["src_x"] = imageComponent.m_SrcRect.x;
            tile["src_y"] = imageComponent.m_SrcRect.y;
            tile["src_width"] = imageComponent.m_SrcRect.width;
            tile["src_height"] = imageComponent.m_SrcRect.height;

            auto &transform2D = world.get<Transform2D>(tileEntity);

            tile["x"] = transform2D.m_Pos.x;
            tile["y"] = transform2D.m_Pos.y;

            if (world.has<LayerOneComponent>(tileEntity))
            {
                tile["layer"] = 1;
            }

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

    mapDataComponent.m_Column = fromJson.value("column", 0);

    if (mapDataComponent.m_Column == 0)
    {
        spdlog::error("Mandatory column field not found or invalid");
        return false;
    }

    mapDataComponent.m_Row = fromJson.value("row", 0);

    if (mapDataComponent.m_Row == 0)
    {
        spdlog::error("Mandatory row field not found or invalid");
        return false;
    }

    mapDataComponent.m_Tiles.resize((size_t)mapDataComponent.m_Column * mapDataComponent.m_Row);

    const auto& tileList = fromJson.value("tilelist", nlohmann::json::array());

    if (tileList.size() == 0)
    {
        spdlog::error("Tile list size of 0");
        return false;
    }

    int i=0;

    for (const auto& tiles : tileList)
    {
        const uint32_t col = i % mapDataComponent.m_Column;
        const uint32_t row = i / mapDataComponent.m_Column;

        for (const auto& tile : tiles)
        {
            gaia::ecs::Entity entity = world.add();
            u_int32_t textureHash = tile["texture_hash"];

            const Texture2D* texture = TextureManager::GetTexture(textureHash);

            if (texture == nullptr)
            {
                spdlog::error("Got texture hash {} but could not find it in TextureManager",textureHash);
                return false;
            }

            ImageComponent imageComponent;
            imageComponent.m_TextureHash = textureHash;
            imageComponent.m_Texture = *texture;
            imageComponent.m_SrcRect = {
                (float) tile.value("src_x",0),
                (float) tile.value("src_y",0),
                (float) tile.value("src_width",0),
                (float) tile.value("src_height",0)
            };

            world.add<ImageComponent>(entity, std::move(imageComponent));
            world.add<GridCellComponent>(entity, {col, row});

            Transform2D transform2D;
            transform2D.m_Pos = {
                (float) tile.value("x", 0),
                (float) tile.value("y", 0)
            };
            world.add<Transform2D>(entity, std::move(transform2D));

            int layer = tile.value("layer", 1);

            switch(layer)
            {
                case 1:
                    world.add<LayerOneComponent>(entity);
                    break;
            }

            mapDataComponent.m_Tiles[(size_t)i].push_back(entity);
        }

        i++;
    }

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
