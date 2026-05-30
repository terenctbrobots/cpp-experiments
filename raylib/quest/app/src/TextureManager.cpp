#include "TextureManager.h"

#include "Components/TextureManagerComponent.h"


bool TextureManager::Add(gaia::ecs::World& world, Texture2D& newTexture)
{
    gaia::ecs::Entity textureManagerEntity = Get(world);

    if (textureManagerEntity == gaia::ecs::EntityBad)
    {
        textureManagerEntity = world.add();
        world.add<TextureManagerComponent>(textureManagerEntity);
    }

    auto& textureManagerComponet = world.set<TextureManagerComponent>(textureManagerEntity);

    if (textureManagerComponet.m_TextureList.count(newTexture.id) == 0)
    {
        textureManagerComponet.m_TextureList.emplace(newTexture.id, newTexture);
        return true;
    }

    return false;
}

gaia::ecs::Entity TextureManager::Get(gaia::ecs::World& world)
{
    world.query().all<TextureManagerComponent>().each([&](gaia::ecs::Entity e)
    {
        return e;
    });

    return gaia::ecs::EntityBad;
}


bool TextureManager::Remove(gaia::ecs::World& world, Texture2D& oldTexture)
{
    return true;
}

void TextureManager::Clear(gaia::ecs::World& world)
{
    gaia::ecs::Entity textureManagerEntity = Get(world);

    if (textureManagerEntity != gaia::ecs::EntityBad)
    {
        auto& textureManagerComponent = world.get<TextureManagerComponent>(textureManagerEntity);

        for (const auto& [key, texture] : textureManagerComponent.m_TextureList)
        {
            UnloadTexture(texture);
        }
    }
}
