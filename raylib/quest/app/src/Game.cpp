#include "Game.h"

#include "Components/SpriteComponent.h"
#include "Systems/MovementSystem.h"

void Game::RegisterSystems()
{
    RegisterMovementSystem(m_World);
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
