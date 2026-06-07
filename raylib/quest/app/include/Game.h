#pragma once

#include "Systems/AnimationSystem.h"
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

    void SetupTileMap();
    void RegisterSystems(float& dt);

    void Update(float& dt);
    void Render();

    void Cleanup();

    private:
    gaia::ecs::World& m_World;

    TileMap m_TileMap;

    RenderSystem m_RenderSystem;
    MovementSystem m_MovementSystem;
    AnimationSystem m_AnimationSystem;
};
