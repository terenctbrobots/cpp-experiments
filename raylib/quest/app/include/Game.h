#pragma once

#include "Systems/AnimationSystem.h"
#include "Systems/CollisionSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/RenderSystem.h"
#include "TileMap.h"

#include <gaia.h>

class Game
{
    public:
    Game(gaia::ecs::World& world) : m_World(world)
    {
    }

    bool Initialize();
    void RegisterSystems();

    void Update(float dt);
    void Render();

    // Debug
    static bool IsDebug();
    // Temporary function to test loading tilemaps
    void LoadTileMap();

    void Cleanup();

    private:
    gaia::ecs::World& m_World;

    TileMap m_TileMap;

    RenderSystem m_RenderSystem;
    MovementSystem m_MovementSystem;
    AnimationSystem m_AnimationSystem;
    CollisionSystem m_CollisionSystem;
};
