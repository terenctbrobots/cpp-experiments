#include "Game.h"

#include "Components/ImageComponent.h"
#include "Systems/AnimationSystem.h"
#include "Systems/MovementSystem.h"
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

    // movement system execute AFTER animation System
    m_World.add(movementSystem.entity(), gaia::ecs::Pair{gaia::ecs::DependsOn, animationSystem.entity()});

    m_RenderSystem.Init(m_World);
}

void Game::Update(float& dt)
{
}

void Game::Render()
{
    m_RenderSystem.Update();
}

void Game::Cleanup()
{
    TextureManager::Clear();
}
