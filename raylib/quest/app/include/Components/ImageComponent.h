#pragma once

#include "raylib.h"

#include <cstdint>

struct ImageComponent
{
    Texture2D m_Texture;
    Rectangle m_SrcRect;
    Vector2 m_Offset = Vector2{0, 0};
    bool m_Flip;
};