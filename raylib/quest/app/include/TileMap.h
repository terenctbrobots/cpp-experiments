#pragma once

#include "raylib.h"

#include <gaia.h>
#include <string>

namespace TileMap
{
    gaia::ecs::Entity CreateMap(gaia::ecs::World &world, std::string &name, int width, int height);
}