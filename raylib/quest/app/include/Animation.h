#pragma once

#include "gaia.h"
#include <string>
#include "Hash.h"

// Forward Declare
struct AnimationDataComponent;

namespace Animation
{
    bool Load(const std::string& fileName, AnimationDataComponent& animationData);
    void SetAnimation(gaia::ecs::World& world, gaia::ecs::Entity entity, const uint32_t animationName);

    const uint32_t MOVE_LEFT = HS("move_left");
    const uint32_t MOVE_RIGHT = HS("move_right");
    const uint32_t MOVE_UP = HS("move_up");
    const uint32_t MOVE_DOWN = HS("move_down");

    const uint32_t IDLE_LEFT = HS("idle_left");
    const uint32_t IDLE_RIGHT = HS("idle_right");
    const uint32_t IDLE_UP = HS("idle_up");
    const uint32_t IDLE_DOWN = HS("idle_down");

    const uint32_t ATTACK_LEFT = HS("attack_left");
    const uint32_t ATTACK_RIGHT = HS("attack_right");
    const uint32_t ATTACK_UP = HS("attack_up");
    const uint32_t ATTACK_DOWN = HS("attack_down");
}