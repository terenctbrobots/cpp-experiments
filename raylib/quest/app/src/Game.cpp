#include "Game.h"

#include "Components/ImageComponent.h"
#include "Systems/AnimationSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/RenderSystem.h"
#include "TextureManager.h"
#include "TileList.h"
#include "TileMap.h"

void Game::SetupTileMap()
{
    TileList::LoadTileList();
    TileMapConfig defaultConfig = {"default", 10, 10, 16, 16};

    TileMap::Create(m_World, defaultConfig);
}

void Game::RegisterSystems(float& dt)
{
    auto animationSystem = RegisterAnimationSystem(m_World, dt);
    auto movementSystem = RegisterMovementSystem(m_World, dt);

    auto renderLayerOneSystem = RegisterRenderLayerOneSystem(m_World);
    auto renderLayerTwoSystem = RegisterRenderLayerTwoSystem(m_World);
    auto renderLayerThreeSystem = RegisterRenderLayerThreeSystem(m_World);

    // movement system execute AFTER animation System
    m_World.add(movementSystem.entity(), gaia::ecs::Pair{gaia::ecs::DependsOn, animationSystem.entity()});
    // render layer one systems exeecutes AFTER movement System
    m_World.add(renderLayerOneSystem.entity(), gaia::ecs::Pair{gaia::ecs::DependsOn, movementSystem.entity()});
    // render layer two systems executes AFTER render layer one
    m_World.add(renderLayerTwoSystem.entity(), gaia::ecs::Pair{gaia::ecs::DependsOn, renderLayerOneSystem.entity()});
    // render layer three systems executes AFTER render layer two
    m_World.add(renderLayerThreeSystem.entity(), gaia::ecs::Pair{gaia::ecs::DependsOn, renderLayerTwoSystem.entity()});
}

void Game::Cleanup() { TextureManager::Clear(); }
