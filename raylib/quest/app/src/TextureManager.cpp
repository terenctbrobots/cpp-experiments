#include "TextureManager.h"

#include "Hash.h"

#include <unordered_map>

static std::unordered_map<u_int32_t, Texture2D> s_TextureList;

u_int32_t TextureManager::Add(const std::string& texturePath, const Texture2D& newTexture)
{
    u_int32_t hash = HS(texturePath);

    if (s_TextureList.count(hash) == 0)
    {
        s_TextureList.emplace(hash, newTexture);
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

    return &s_TextureList[hash];
}

const u_int32_t TextureManager::GetHash(const Texture2D& checkTexture)
{
    for (const auto& [key, texture] : s_TextureList)
    {
        if (texture.id == checkTexture.id)
        {
            return key;
        }
        UnloadTexture(texture);
    }

    return 0;
}

void TextureManager::Clear()
{
    for (const auto& [key, texture] : s_TextureList)
    {
        UnloadTexture(texture);
    }
    s_TextureList.clear();
}
