#pragma once

#include <gaia.h>

class Game
{
    public:
        Game(gaia::ecs::World & world) : m_World(world) {}

        void RegisterSystems();
        void Cleanup();
    private:
        gaia::ecs::World& m_World;
};
