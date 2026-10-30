#pragma once

#include <gaia.h>

struct CollisionSystem
{
    gaia::ecs::Query m_PlayerQuery;
    gaia::ecs::Query m_EnemyQuery;

    void Init(gaia::ecs::World& world);
    void Update(float& dt);
};
