#include "TextureManager.h"

#include "Hash.h"
#include "spdlog/spdlog.h"

#include <fstream>
#include <nlohmann/json.hpp>
#include <raylib.h>
#include <unordered_map>

static std::unordered_map<std::string, TextureManager::Texture> s_TextureList;
static TextureManager::Texture s_EmptyTexture = {TextureManager::TextureType::Invalid, "", "", {}};

bool TextureManager::Initialize()
{
    if (!s_TextureList.empty())
    {
        Clear();
    }

    std::ifstream file("./assets/textures.json");

    if (!file.is_open())
    {
        spdlog::error("Could not open textures json");
        return false;
    }

    nlohmann::json jsonData = nlohmann::json::parse(file);

    const auto& textureList = jsonData.value("textures", nlohmann::json::array());

    for (const auto texture : textureList)
    {
        std::string key = texture.value("key", "");
        if (key.empty())
        {
            spdlog::warn("Mandatory key field in textures not found");
            continue;
        }

        Texture newTexture;

        std::string textureType = texture.value("type", "");

        if (textureType.empty())
        {
            spdlog::warn("Mandatory type field in textures not found");
            continue;
        }

        if (textureType == "sprite")
        {
            newTexture.m_TextureType = TextureType::Sprite;
        }
        else if (textureType == "tileset")
        {
            newTexture.m_TextureType = TextureType::TileSet;
        }
        else
        {
            spdlog::warn("Unknown texture type detected");
            continue;
        }

        newTexture.m_Path = texture.value("path", "");
        newTexture.m_DataPath = texture.value("data", "");

        if (newTexture.m_Path.empty() || newTexture.m_DataPath.empty())
        {
            spdlog::warn("Empty graphic or data path");
            continue;
        }

        s_TextureList.emplace(key, std::move(newTexture));
    }

    return true;
}

const TextureManager::Texture& TextureManager::Load(const std::string& key)
{
    auto it = s_TextureList.find(key);
    if (it != s_TextureList.end())
    {
        Texture& texture = it->second;

        texture.m_Texture = LoadTexture(texture.m_Path.c_str());
        return texture;
    }

    return s_EmptyTexture;
}

// u_int32_t TextureManager::Add(const std::string& texturePath, const Texture2D& newTexture2D,
//                               TextureManager::TextureType textureType)
// {
//     u_int32_t hash = HS(texturePath);

//     if (s_TextureList.count(hash) == 0)
//     {
//         Texture newTexture;
//         newTexture.m_Path = texturePath;
//         newTexture.m_Texture = newTexture2D;
//         newTexture.m_TextureType = textureType;

//         s_TextureList.emplace(hash, std::move(newTexture));
//         spdlog::info("TExture hash {}", hash);
//         return hash;
//     }

//     return 0;
// }

// const Texture2D* TextureManager::GetTexture(u_int32_t hash)
// {
//     if (s_TextureList.count(hash) == 0)
//     {
//         return nullptr;
//     }

//     return &s_TextureList[hash].m_Texture;
// }

// const u_int32_t TextureManager::GetHash(const Texture2D& checkTexture)
// {
//     for (const auto& [key, texture] : s_TextureList)
//     {
//         if (texture.m_Texture.id == checkTexture.id)
//         {
//             return key;
//         }
//     }

//     return 0;
// }

void TextureManager::Clear()
{
    for (const auto& [key, texture] : s_TextureList)
    {
        UnloadTexture(texture.m_Texture);
    }
    s_TextureList.clear();
}

void TextureManager::Clear(TextureManager::TextureType textureType)
{
    // std::unordered_map<u_int32_t, TextureManager::Texture> newTextureList;

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
