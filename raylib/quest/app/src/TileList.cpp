#include "TileList.h"

#include "Hash.h"
#include "TextureManager.h"
#include "raylib.h"
#include "spdlog/spdlog.h"

#include <fstream>
#include <nlohmann/json.hpp>

static std::unordered_map<u_int32_t, TileList::Tile> s_TileList;

const std::string s_PlainsTexture = "plains";

bool TileList::LoadTileList()
{
    bool returnResult = false;

    auto& plainsTexture = TextureManager::Load(s_PlainsTexture);

    if (!IsTextureValid(plainsTexture.m_Texture))
    {
        spdlog::error("Could not load texture");
        return false;
    }

    returnResult = LoadTileSet(s_PlainsTexture, plainsTexture);
    return true;
}

bool TileList::LoadTileSet(const std::string& textureKey, const TextureManager::Texture& texture)
{
    std::ifstream file(texture.m_DataPath);

    if (!file.is_open())
    {
        spdlog::error("Could not open {} json file", texture.m_DataPath);
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
            newTile.m_TextureKey = textureKey;
            newTile.m_Texture = texture.m_Texture;
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
            newTile.m_Texture = texture.m_Texture;
            newTile.m_TextureKey = textureKey;

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
