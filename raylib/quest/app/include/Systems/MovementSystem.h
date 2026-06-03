#pragma once

#include <gaia.h>

struct MovementSystem
{
    gaia::ecs::Query m_Query;

    void Init(gaia::ecs::World& world);
    void Update(float& dt);
};
