#pragma once
#include <gaia.h>

namespace Player
{
    gaia::ecs::Entity Create(gaia::ecs::World& world);
    void Move(gaia::ecs::World& world, float dt);
}
