#pragma once

#include <string>

struct AnimationComponent
{
    std::string m_CurrentAnimation;
    u_int16_t m_CurrentFrame;
    float m_Timer;
};