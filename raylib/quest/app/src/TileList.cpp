#include "TileList.h"

#include "Hash.h"
#include "TextureManager.h"
#include "raylib.h"
#include "spdlog/spdlog.h"

#include <fstream>
#include <nlohmann/json.hpp>

static std::unordered_map<u_int32_t, TileList::Tile> s_TileList;

bool TileList::LoadTileList()
{
    bool returnResult = false;

    returnResult = LoadTileSet("./assets/tilesets/plains.json", "./assets/tilesets/plains.png");
    return returnResult;
}

bool TileList::LoadTileSet(const std::string& tileSetFilename, const std::string& textureFilename)
{
    Texture2D tilesetTexture = LoadTexture(textureFilename.c_str());

    if (tilesetTexture.id <= 0)
    {
        spdlog::error("Could not load Tileset Texture {}", textureFilename);
        return false;
    }

    u_int32_t textureHash = TextureManager::Add(tileSetFilename, tilesetTexture, TextureManager::TextureType::TileList);

    if (textureHash == 0)
    {
        spdlog::error("Could not load texture, duplicate exists");
        return false;
    }

    std::ifstream file(tileSetFilename);

    if (!file.is_open())
    {
        spdlog::error("Could not open {} json file", tileSetFilename);
        return false;
    }

    nlohmann::json jsonData = nlohmann::json::parse(file);

    if (jsonData["name"] == nullptr)
    {
        spdlog::error("Mandatory name field not found");
        return false;
    }

    const std::string name = jsonData["name"];

    if (jsonData["tile_width"] == nullptr)
    {
        spdlog::error("Mandatory tile width field not found");
        return false;
    }

    const float tileWidth = jsonData["tile_width"];

    if (jsonData["tile_height"] == nullptr)
    {
        spdlog::error("Mandatory tile height field not found");
        return false;
    }

    const float tileHeight = jsonData["tile_height"];

    if (jsonData["column"] == nullptr)
    {
        spdlog::error("Mandatory column field not found");
        return false;
    }

    const int column = jsonData["column"];

    if (jsonData["row"] == nullptr)
    {
        spdlog::error("Mandatory row field not found");
        return false;
    }

    const int row = jsonData["row"];

    int tileCount = 0;

    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x < column; x++)
        {
            std::string baseName = name;
            baseName += std::to_string(tileCount++);

            Tile newTile;
            newTile.m_Name = baseName;
            newTile.m_TextureHash = textureHash;
            newTile.m_Texture = tilesetTexture;
            newTile.m_SrcRect = {x * tileWidth, y * tileHeight, tileWidth, tileHeight};

            u_int32_t key = HS(baseName);

            auto [it, inserted] = s_TileList.try_emplace(key, newTile);

            if (!inserted)
            {
                spdlog::warn("Duplicate tile name found {}", baseName);
            }
        }
    }

    if (jsonData["unique"] != nullptr)
    {
        nlohmann::json uniqueListJson = jsonData["unique"];

        for (auto& uniqueJson : uniqueListJson.items())
        {
            nlohmann::json tileJson = uniqueJson.value();

            Tile newTile;
            newTile.m_Name = uniqueJson.key();
            newTile.m_Texture = tilesetTexture;

            if (tileJson["x"] == nullptr)
            {
                spdlog::error("Mandatory x value on unique tile not found");
                return false;
            }

            int x = tileJson["x"];

            if (tileJson["y"] == nullptr)
            {
                spdlog::error("Mandatory y value on unique tile not found");
                return false;
            }
            int y = tileJson["y"];

            newTile.m_SrcRect = {x * tileWidth, y * tileHeight, tileWidth, tileHeight};

            u_int32_t key = HS(newTile.m_Name);

            auto [it, inserted] = s_TileList.try_emplace(key, newTile);

            if (!inserted)
            {
                spdlog::warn("Duplicate tile name found {}", newTile.m_Name);
            }
        }
    }

    return true;
}

const TileList::Tile* TileList::Get(const u_int32_t tileId)
{
    auto it = s_TileList.find(tileId);
    if (it != s_TileList.end())
    {
        return &it->second;
    }

    return nullptr;
}