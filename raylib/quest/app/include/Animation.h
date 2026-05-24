#pragma once

#include "gaia.h"
#include <string>

// Forward Declare
struct AnimationDataComponent;

namespace Animation
{
    bool Load(const std::string& fileName, AnimationDataComponent& animationData);
    void SetAnimation(gaia::ecs::World& world, gaia::ecs::Entity entity, const std::string& animationName);
}