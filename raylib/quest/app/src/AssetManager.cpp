#include "AssetManager.h"

#include "Animation.h"
#include "spdlog/spdlog.h"

#include <fstream>
#include <nlohmann/json.hpp>

static tsl::robin_map<std::string, AssetManager::Asset> s_AssetList;
static AssetManager::Asset s_EmptyAsset = {AssetManager::AssetType::Invalid, "", "", {0}};

namespace
{
    bool LoadAnimation(const std::string& fileName, Animation::AnimationData& animation)
    {
        std::ifstream file(fileName);

        if (!file.is_open())
        {
            spdlog::error("Could not open {} json file", fileName);
            return false;
        }
        nlohmann::json jsonData = nlohmann::json::parse(file);

        if (!jsonData.contains("width"))
        {
            spdlog::error("Mandatory width field not found");
            return false;
        }
        animation.m_Width = jsonData.value("width", 64);

        if (!jsonData.contains("height"))
        {
            spdlog::error("Mandatory height field not found");
        }
        animation.m_Height = jsonData.value("height", 64);

        if (jsonData.contains("origin"))
        {
            std::string origin = jsonData.value("origin", "center");

            // If origin center draw sprite half the width left and half the height up
            if (origin == "center")
            {
                animation.m_Offset = {-(animation.m_Width / 2), -(animation.m_Height / 2)};
            }
        }

        if (!jsonData.contains("defaultAnimation"))
        {
            spdlog::error("Mandatory defaultAnimation field not found");
        }
        animation.m_DefaultAnimation = HS(jsonData["defaultAnimation"]);

        animation.m_AnimationList.clear();

        nlohmann::json animationListJson = jsonData["animation"];

        for (auto& animationJson : animationListJson.items())
        {
            nlohmann::json frameJson = animationJson.value();

            Animation::AnimationFrame frameData;
            if (!frameJson.contains("frameRate") || frameJson.value("frameRate", 0) == 0)
            {
                spdlog::error("Mandatory frameRate field not found or zero");
                return false;
            }

            frameData.m_FrameDuration = 1.0f / (float)frameJson.value("frameRate", 200);

            if (!frameJson.contains("frames"))
            {
                spdlog::error("Mandatory frames field not found");
                return false;
            }

            frameData.m_Frames = frameJson.value("frames", 1);

            if (frameJson.contains("flip"))
            {
                frameData.m_Flip = frameJson.value("flip", false);
            }
            else
            {
                frameData.m_Flip = false;
            }

            float x = 0;
            float y = 0;

            if (frameJson.contains("x"))
            {
                x = frameJson.value("x", 0);
            }

            if (frameJson.contains("y"))
            {
                y = frameJson.value("y", 0);
            }

            for (int i = 0; i < frameData.m_Frames; i++)
            {
                frameData.m_FrameList.push_back({x, y, animation.m_Width, animation.m_Height});
                x += animation.m_Width;
            }

            const uint32_t key = HS(animationJson.key());

            auto [it, inserted] = animation.m_AnimationList.try_emplace(key, frameData);

            if (!inserted)
            {
                spdlog::warn("Duplicate key {} found", animationJson.key());
            }
        }

        return true;
    }
} // namespace

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

const AssetManager::Asset& AssetManager::GetAsset(const std::string& key)
{
    auto it = s_AssetList.find(key);
    if (it != s_AssetList.end())
    {
        return it->second;
    }

    return s_EmptyAsset;
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

            if (updateAsset.m_AssetType == AssetType::Sprite)
            {
                LoadAnimation(updateAsset.m_DataPath, updateAsset.m_Animation);
            }

            s_AssetList.insert_or_assign(key, std::move(updateAsset));
            return newTexture;
        }
        return it->second.m_Texture;
    }

    spdlog::warn("Asset key '{}' not found, returning empty fallback texture", key);
    return s_EmptyAsset.m_Texture;
}

const Animation::AnimationData* AssetManager::GetAnimation(const std::string& key)
{
    auto it = s_AssetList.find(key);

    if (it != s_AssetList.end())
    {
        if (!IsTextureValid(it->second.m_Texture))
        {
            spdlog::warn("Animation'{}' has an invalid texture", key);
            return nullptr;
        }

        return &it->second.m_Animation;
    }

    return nullptr;
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
