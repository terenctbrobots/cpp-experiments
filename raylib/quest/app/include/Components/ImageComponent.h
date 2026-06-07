#pragma once

#include "raylib.h"

#include <cstdint>

struct ImageComponent
{
    Texture2D m_Texture;
    u_int32_t m_TextureHash = 0;
    Rectangle m_SrcRect = {0, 0, 0, 0};
    Vector2 m_Offset = Vector2{0, 0};
    bool m_Flip = false;
};