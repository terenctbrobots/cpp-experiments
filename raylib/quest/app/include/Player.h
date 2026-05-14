#pragma once
#include <gaia.h>

namespace Player
{
    bool Create(gaia::ecs::World& world);
    void Move(gaia::ecs::World& world, float speed, float dt, float x, float y);
}
