#pragma once

#include "Systems/RenderSystem.h"

#include <gaia.h>

class Game
{
    public:
    Game(gaia::ecs::World& world) : m_World(world) {}

    void SetupTileMap();
    void RegisterSystems(float& dt);

    void Update(float& dt);
    void Render();

    void Cleanup();

    private:
    gaia::ecs::World& m_World;
    RenderSystem m_RenderSystem;
};
