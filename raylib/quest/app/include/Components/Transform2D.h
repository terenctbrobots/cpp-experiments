#pragma once
#include "raylib.h"

struct Transform2D
{
    float m_X;
    float m_Y;

    operator Vector2() const { return {m_X, m_Y}; }
};