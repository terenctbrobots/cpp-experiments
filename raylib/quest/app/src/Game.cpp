#include "Game.h"

#include "AssetManager.h"
#include "TileList.h"
#include "TileMap.h"
#include "spdlog/spdlog.h"

static bool s_Debug = false;

bool Game::Initialize()
{
    if (!AssetManager::Initialize())
    {
        return false;
    }

    TileList::LoadTileList();
    TileMapConfig defaultConfig = {"default", 60, 60, 16, 16};

    m_TileMap = TileMap::Create(m_World, defaultConfig);
    m_TileMap.Save(m_World, "./test.json");

    return true;
}

void Game::RegisterSystems()
{
    m_AnimationSystem.Init(m_World);
    m_CollisionSystem.Init(m_World);
    m_MovementSystem.Init(m_World);

    m_RenderSystem.Init(m_World);
}

void Game::Update(float dt)
{
    m_AnimationSystem.Update(dt);
    m_CollisionSystem.Update(dt); // Collision runs before Movement, so it can cancel velocity if needed
    m_MovementSystem.Update(dt);
}

void Game::Render()
{
    m_RenderSystem.Update();
}

bool Game::IsDebug()
{
    return s_Debug;
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
    AssetManager::Clear();
}
