#pragma once

#include <gaia.h>

struct AnimationSystem
{
    gaia::ecs::Query m_Query;

    void Init(gaia::ecs::World& world);
    void Update(float& dt);
};