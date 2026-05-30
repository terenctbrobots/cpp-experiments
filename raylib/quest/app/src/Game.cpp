#include "Game.h"

#include "TextureManager.h"
#include "Components/ImageComponent.h"
#include "Systems/AnimationSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/RenderSystem.h"

void Game::RegisterSystems(float& dt)
{
    auto animationSystem = RegisterAnimationSystem(m_World, dt);
    auto movementSystem = RegisterMovementSystem(m_World, dt);
    auto renderSystem = RegisterRenderSystem(m_World);

    // movement system execute AFTER animation System
    m_World.add(movementSystem.entity(), gaia::ecs::Pair{gaia::ecs::DependsOn, animationSystem.entity()});
    // render systems exeecutes AFTER movement System
    m_World.add(renderSystem.entity(), gaia::ecs::Pair{gaia::ecs::DependsOn, movementSystem.entity()});
}

void Game::Cleanup()
{
    TextureManager::Clear(m_World);
}
