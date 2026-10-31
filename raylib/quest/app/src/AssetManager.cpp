#include "AssetManager.h"

#include "spdlog/spdlog.h"

#include <fstream>
#include <nlohmann/json.hpp>

static tsl::robin_map<std::string, AssetManager::Asset> s_AssetList;
static AssetManager::Asset s_EmptyAsset = {AssetManager::AssetType::Invalid, "", "", {0}};

bool AssetManager::Initialize()
{
    if (!s_AssetList.empty())
    {
        Clear();
    }

    std::ifstream file("./assets/assets.json");
    if (!file.is_open())
    {
        spdlog::error("Could not open assets json");
        return false;
    }

    nlohmann::json jsonData = nlohmann::json::parse(file, nullptr, false);
    if (jsonData.is_discarded())
    {
        spdlog::error("Failed to parse assets.json");
        return false;
    }

    for (auto& [key, entry] : jsonData.items())
    {
        std::string assetType = entry.value("type", "");
        if (assetType.empty())
        {
            spdlog::warn("Mandatory 'type' field in assets.json missing for key: {}", key);
            continue;
        }

        Asset newAsset;
        if (assetType == "sprite")
        {
            newAsset.m_AssetType = AssetType::Sprite;
        }
        else if (assetType == "tileset")
        {
            newAsset.m_AssetType = AssetType::TileSet;
        }
        else
        {
            spdlog::warn("Unknown asset type '{}' for key: {}", assetType, key);
            continue;
        }

        newAsset.m_Path = entry.value("path", "");
        newAsset.m_DataPath = entry.value("data", "");
        newAsset.m_Texture.id = 0; // Raylib Null Object Pattern ID

        if (newAsset.m_Path.empty() || newAsset.m_DataPath.empty())
        {
            spdlog::warn("Empty path or data path for key: {}", key);
            continue;
        }

        s_AssetList.emplace(key, std::move(newAsset));
    }

    return true;
}

Texture2D AssetManager::GetTexture(const std::string& key)
{
    auto it = s_AssetList.find(key);
    if (it != s_AssetList.end())
    {
        // Lazy loading: Load into VRAM on demand
        if (!IsTextureValid(it->second.m_Texture))
        {
            Asset updateAsset = it->second;

            Texture2D newTexture = LoadTexture(it->second.m_Path.c_str());
            updateAsset.m_Texture = newTexture;

            s_AssetList.emplace(key, std::move(updateAsset));
            return newTexture;
        }
        return it->second.m_Texture;
    }

    spdlog::warn("Asset key '{}' not found, returning empty fallback texture", key);
    return s_EmptyAsset.m_Texture;
}

void AssetManager::Clear()
{
    for (auto& [key, asset] : s_AssetList)
    {
        if (IsTextureValid(asset.m_Texture))
        {
            UnloadTexture(asset.m_Texture);
        }
    }
    s_AssetList.clear();
}
