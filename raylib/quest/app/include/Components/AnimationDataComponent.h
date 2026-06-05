#pragma once

#include "raylib.h"

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

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

    Vector2 m_Offset;

    uint32_t m_DefaultAnimation;

    std::unordered_map<uint32_t, AnimationFrame> m_AnimationList;
};