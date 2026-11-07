#pragma once

#include "raylib.h"

namespace Animation
{
    struct ImageComponent
    {
        Texture2D m_Texture;
        Rectangle m_SrcRect = {0, 0, 0, 0};
        Vector2 m_Offset = Vector2{0, 0};
        bool m_Flip = false;
    };
} // namespace Animation
