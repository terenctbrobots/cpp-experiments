#include "Game.h"

#include "Components/SpriteComponent.h"

void Game::RegisterSystems()
{

}

void Game::Cleanup()
{
    gaia::ecs::Query q = m_World.query()
    .all<SpriteComponent>();

    q.each([&] (const SpriteComponent& sprite)
    {
        UnloadTexture(sprite.m_Texture);
    });
}
