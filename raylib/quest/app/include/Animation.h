#pragma once

#include <string>

// Forward Declare
struct AnimationDataComponent;

namespace Animation
{
    bool Load(const std::string& fileName, AnimationDataComponent& animationData);
}