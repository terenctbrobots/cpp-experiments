#pragma once

#include "parallel_hashmap/phmap.h"
#include "raylib.h"

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

    Vector2 m_Offset = Vector2{0, 0};

    uint32_t m_DefaultAnimation;

    phmap::flat_hash_map<uint32_t, AnimationFrame> m_AnimationList;
};
