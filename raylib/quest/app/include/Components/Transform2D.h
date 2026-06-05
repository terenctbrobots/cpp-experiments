#pragma once
#include "raylib.h"
#include "raymath.h"

struct Transform2D
{
    Vector2 m_Pos;
};

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