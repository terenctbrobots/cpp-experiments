#include "TextureManager.h"

#include <unordered_map>

static std::unordered_map<unsigned int, Texture2D> s_TextureList;

bool TextureManager::Add(Texture2D &newTexture)
{
    if (s_TextureList.count(newTexture.id) == 0)
    {
        s_TextureList.emplace(newTexture.id, newTexture);
        return true;
    }

    return false;
}

bool TextureManager::Remove(Texture2D &oldTexture) { return true; }

void TextureManager::Clear()
{
    for (const auto &[key, texture] : s_TextureList)
    {
        UnloadTexture(texture);
    }
    s_TextureList.clear();
}
