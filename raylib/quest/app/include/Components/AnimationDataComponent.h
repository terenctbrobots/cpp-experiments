#pragma once

#include "raylib.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstdint>

struct AnimationFrame
{
    std::vector<Rectangle> m_FrameList;
    float m_FrameDuration;
    u_int m_Frames;
    bool m_Flip;
};

struct AnimationDataComponent
{
    float m_Width;
    float m_Height;

    uint32_t m_DefaultAnimation;

    std::unordered_map<uint32_t, AnimationFrame> m_AnimationList;
};