#include "raylib.h"
#include <gaia.h>

namespace TextureManager
{
    bool Add(gaia::ecs::World& world, Texture2D& newTexture);
    bool Remove(gaia::ecs::World& world, Texture2D& oldTexture);
    gaia::ecs::Entity Get(gaia::ecs::World& world);
    void Clear(gaia::ecs::World& world);
}