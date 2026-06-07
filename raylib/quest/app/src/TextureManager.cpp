#include "TextureManager.h"

#include "Hash.h"

#include <unordered_map>

static std::unordered_map<u_int32_t, TextureManager::Texture> s_TextureList;

u_int32_t TextureManager::Add(const std::string& texturePath, const Texture2D& newTexture2D,
                              TextureManager::TextureType textureType)
{
    u_int32_t hash = HS(texturePath);

    if (s_TextureList.count(hash) == 0)
    {
        Texture newTexture;
        newTexture.m_Path = texturePath;
        newTexture.m_Texture = newTexture2D;
        newTexture.m_TextureType = textureType;

        s_TextureList.emplace(hash, std::move(newTexture));
        return hash;
    }

    return 0;
}

const Texture2D* TextureManager::GetTexture(u_int32_t hash)
{
    if (s_TextureList.count(hash) == 0)
    {
        return nullptr;
    }

    return &s_TextureList[hash].m_Texture;
}

const u_int32_t TextureManager::GetHash(const Texture2D& checkTexture)
{
    for (const auto& [key, texture] : s_TextureList)
    {
        if (texture.m_Texture.id == checkTexture.id)
        {
            return key;
        }
    }

    return 0;
}

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
    std::unordered_map<u_int32_t, TextureManager::Texture> newTextureList;

    for (const auto& [key, texture] : s_TextureList)
    {
        if (texture.m_TextureType == textureType)
        {
            UnloadTexture(texture.m_Texture);
        }
        else
        {
            newTextureList.emplace(key, texture);
        }
    }

    s_TextureList.clear();
    s_TextureList = std::move(newTextureList);
}
