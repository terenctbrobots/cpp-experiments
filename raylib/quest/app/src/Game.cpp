#include "Game.h"

#include "Components/SpriteComponent.h"

namespace Game
{
    void Cleanup(gaia::ecs::World& world)
    {
        gaia::ecs::Query q = world.query()
        .all<SpriteComponent>();

    q.each([&] (const SpriteComponent& sprite)
    {
        UnloadTexture(sprite.m_Texture);
    });
    }
}