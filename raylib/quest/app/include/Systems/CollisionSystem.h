#pragma once

#include <gaia.h>

struct CollisionSystem
{
    gaia::ecs::Query m_Query;

    void Init(gaia::ecs::World& world);
    void Update(float dt);
};
