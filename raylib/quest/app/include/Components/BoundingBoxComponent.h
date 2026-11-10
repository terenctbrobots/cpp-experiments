#pragma once

#include "raylib.h"

namespace Gameplay
{
    struct BoundingBoxComponent
    {
        Vector2 m_Offset = {0, 0};
        float m_Width;
        float m_Height;
        Rectangle m_Collision = {0, 0, 0, 0};
        float m_InvMass = 0.5f;
        bool m_Static = false;
        bool m_Show = true;
    };
} // namespace Gameplay
