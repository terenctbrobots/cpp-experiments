#include "TextureManager.h"

static std::unordered_map<unsigned int, Texture2D> TextureList;

bool TextureManager::Add(gaia::ecs::World& world, Texture2D& newTexture)
{
    if (TextureList.count(newTexture.id) == 0)
    {
        TextureList.emplace(newTexture.id, newTexture);
        return true;
    }

    return false;
}

bool TextureManager::Remove(gaia::ecs::World& world, Texture2D& oldTexture)
{
    return true;
}

void TextureManager::Clear(gaia::ecs::World& world)
{
    for (const auto& [key, texture] : TextureList)
    {
        UnloadTexture(texture);
    }
    TextureList.clear();
}
