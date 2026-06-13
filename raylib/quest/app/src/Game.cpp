#include "Game.h"

#include "TextureManager.h"
#include "TileList.h"
#include "TileMap.h"
#include "spdlog/spdlog.h"

void Game::SetupTileMap()
{
    TileList::LoadTileList();
    TileMapConfig defaultConfig = {"default", 60, 60, 16, 16};

    m_TileMap = TileMap::Create(m_World, defaultConfig);
    m_TileMap.Save(m_World, "./test.json");
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

void Game::LoadTileMap()
{
    spdlog::info("Loading TileMap");
    m_TileMap.Destroy(m_World);
    m_TileMap.Load(m_World, "./test.json");
    spdlog::info("Loading complete");
}

void Game::Cleanup()
{
    TextureManager::Clear();
}
