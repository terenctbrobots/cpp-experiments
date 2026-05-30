#pragma once

#include <cstdint>
#include "raylib.h"

struct ImageComponent
{
    Texture2D m_Texture;
    Rectangle m_SrcRect;
    bool m_Flip;
};