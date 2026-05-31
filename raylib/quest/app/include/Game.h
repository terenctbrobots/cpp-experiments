#pragma once

#include <gaia.h>

class Game
{
    public:
        Game(gaia::ecs::World & world) : m_World(world) {}

        void SetupTileMap();
        void RegisterSystems(float& dt);
        void Cleanup();
    private:
        gaia::ecs::World& m_World;
};
