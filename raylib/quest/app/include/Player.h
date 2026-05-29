#pragma once
#include <gaia.h>
#include "raylib.h"

namespace Player
{
    gaia::ecs::Entity Create(gaia::ecs::World& world);
    void Movement(gaia::ecs::World& world, gaia::ecs::Entity& player, Vector2 direction, uint32_t animationName);
    void Idle(gaia::ecs::World& world, gaia::ecs::Entity& player);
    void Attack(gaia::ecs::World& world, gaia::ecs::Entity& player);
}
