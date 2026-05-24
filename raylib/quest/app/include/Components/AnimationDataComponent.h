#pragma once

#include "raylib.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>

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

    std::string m_DefaultAnimation;

    std::unordered_map<std::string, AnimationFrame> m_AnimationList;
};