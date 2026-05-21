#pragma once

#include "raylib.h"
#include <memory>
#include <vector>
#include <unordered_map>

struct AnimationFrame
{
    std::vector<Rectangle> m_frameList;
    u_int m_FrameRate;
    u_int m_Frames;
    Vector2 m_Offset;
};

struct AnimationDataComponent
{
    float m_Width;
    float m_Height;

    std::unordered_map<std::string, AnimationFrame> m_AnimationList;
};