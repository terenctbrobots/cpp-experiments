#pragma once
#include "raylib.h"

#include <gaia.h>

namespace Player
{
    gaia::ecs::Entity Create(gaia::ecs::World& world);
    void Movement(gaia::ecs::World& world, gaia::ecs::Entity& player, Vector2 direction, uint32_t animationName);
    void Idle(gaia::ecs::World& world, gaia::ecs::Entity& player);
    void Attack(gaia::ecs::World& world, gaia::ecs::Entity& player);
    Vector2 GetPosition(gaia::ecs::World& world, gaia::ecs::Entity& player);
} // namespace Player
