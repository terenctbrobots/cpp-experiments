#pragma once
#include "raylib.h"
#include "raymath.h"

namespace Gameplay
{
    struct Transform2D
    {
        Vector2 m_Pos;
    };
} // namespace Gameplay

inline Vector2& operator+=(Vector2& a, Vector2 b)
{
    a = Vector2Add(a, b);
    return a;
}
inline Vector2& operator-=(Vector2& a, Vector2 b)
{
    a = Vector2Subtract(a, b);
    return a;
}
inline Vector2& operator*=(Vector2& a, float f)
{
    a = Vector2Scale(a, f);
    return a;
}

inline Gameplay::Transform2D& operator+=(Gameplay::Transform2D& a, Vector2 b)
{
    a.m_Pos = Vector2Add(a.m_Pos, b);
    return a;
}

inline Gameplay::Transform2D& operator-=(Gameplay::Transform2D& a, Vector2 b)
{
    a.m_Pos = Vector2Subtract(a.m_Pos, b);
    return a;
}

inline Gameplay::Transform2D& operator*=(Gameplay::Transform2D& a, float f)
{
    a.m_Pos = Vector2Scale(a.m_Pos, f);
    return a;
}
