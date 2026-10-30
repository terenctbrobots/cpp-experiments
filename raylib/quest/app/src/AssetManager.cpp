#include "AssetManager.h"

#include "spdlog/spdlog.h"
#include "tsl/robin_map.h"

#include <fstream>
#include <nlohmann/json.hpp>
#include <raylib.h>

static tsl::robin_map<std::string, AssetManager::Asset> s_AssetList;
static AssetManager::Texture s_EmptyTexture = {AssetManager::TextureType::Invalid, "", "", {}};
static AssetManager::Asset s_EmptyAsset = {AssetManager::AssetType::Invalid, "", "", {}};

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

    nlohmann::json jsonData = nlohmann::json::parse(file);

    for (auto& [key, entry] : jsonData.items())
    {
        std::string assetType = entry.value("type", "");

        if (assetType.empty())
        {
            spdlog::warn("Mandatory 'type' field in assets.json not found");
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
            spdlog::warn("Unknown asset type in assets.json");
            continue;
        }

        newAsset.m_Path = entry.value("path", "");
        newAsset.m_DataPath = entry.value("data", "");
        newAsset.m_Texture.id = 0;

        if (newAsset.m_Path.empty() || newAsset.m_DataPath.empty())
        {
            spdlog::warn("Empty graphic or data path");
            continue;
        }

        s_AssetList.emplace(key, std::move(newAsset));
    }

    return true;
}

const AssetManager::Texture& AssetManager::LoadTexture(const std::string& key)
{
    // auto it = s_TextureList.find(key);
    // if (it != s_TextureList.end())
    // {
    //     if (!IsTextureValid(it->second.m_Texture))
    //     {
    //         it->second.m_Texture = LoadTexture(it->second.m_Path.c_str());
    //     }
    //     return it->second;
    // }

    return s_EmptyTexture;
}

const Texture2D& AssetManager::GetTexture(const std::string& key)
{
    // auto it = s_TextureList.find(key);

    // if (it != s_TextureList.end())
    // {
    //     return it->second.m_Texture;
    // }

    return s_EmptyTexture.m_Texture;
}

void AssetManager::Clear()
{
    // for (const auto& [key, texture] : s_TextureList)
    // {
    //     UnloadTexture(texture.m_Texture);
    // }
    // s_TextureList.clear();
}

void AssetManager::ClearTexture(AssetManager::TextureType textureType)
{
    // std::unordered_map<std::string, AssetManager::Texture> newTextureList;

    // for (const auto& [key, texture] : s_TextureList)
    // {
    //     if (texture.m_TextureType == textureType)
    //     {
    //         UnloadTexture(texture.m_Texture);
    //     }
    //     else
    //     {
    //         newTextureList.emplace(key, texture);
    //     }
    // }

    // s_TextureList.clear();
    // s_TextureList = std::move(newTextureList);
}
