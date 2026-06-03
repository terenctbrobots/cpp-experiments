#include "Game.h"

#include "Components/ImageComponent.h"
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
    m_AnimationSystem.Init(m_World);
    m_MovementSystem.Init(m_World);

    m_RenderSystem.Init(m_World);
}

void Game::Update(float& dt)
{
    m_AnimationSystem.Update(dt);
    m_MovementSystem.Update(dt);
}

void Game::Render()
{
    m_RenderSystem.Update();
}

void Game::Cleanup()
{
    TextureManager::Clear();
}
