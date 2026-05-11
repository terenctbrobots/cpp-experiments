#pragma once

#include <cstdint>

// Forward Declarations
struct Texture2D;
struct Rectangle;

struct SpriteComponent
{
    Texture2D m_Texture;
    Rectangle m_SrcRect;
};