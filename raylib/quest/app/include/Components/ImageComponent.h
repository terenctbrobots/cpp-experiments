#pragma once

#include "raylib.h"

#include <cstdint>

struct ImageComponent
{
    Texture2D m_Texture;
    Rectangle m_SrcRect;
    Vector2 m_Offset;
    bool m_Flip;
};