#include "Game.h"

#include "Components/SpriteComponent.h"
#include "Systems/MovementSystem.h"
#include "Systems/RenderSystem.h"

void Game::RegisterSystems()
{
    auto movementSystem = RegisterMovementSystem(m_World);
    auto renderSystem = RegisterRenderSystem(m_World);

    m_World.add(movementSystem.entity(), gaia::ecs::Pair{gaia::ecs::DependsOn, renderSystem.entity()});
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
