#pragma once

#include "raylib.h"

namespace Game
{
    struct BoundingBoxComponent
    {
        Vector2 m_Offset = {0, 0};
        float m_Width;
        float m_Height;
        Rectangle m_Collision = {0, 0, 0, 0};
        bool m_Static = false;
        bool m_Show = true;
    };
} // namespace Game
