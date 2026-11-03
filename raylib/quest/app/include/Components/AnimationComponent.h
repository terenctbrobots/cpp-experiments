#pragma once

#include "Animation.h"

#include <cstdint>
#include <sys/types.h>

struct AnimationComponent
{
    uint32_t m_CurrentAnimation = 0;
    uint16_t m_CurrentFrame = 0;
    float m_Timer = 0;
};
