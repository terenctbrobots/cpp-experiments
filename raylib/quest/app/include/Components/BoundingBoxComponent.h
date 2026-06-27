#pragma once

#include "raylib.h"

struct BoundingBoxComponent
{
    Rectangle m_Collision;
    bool m_Static = false;
    bool m_Show = false;
};
