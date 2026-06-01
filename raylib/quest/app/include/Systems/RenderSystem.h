#pragma once 

#include <gaia.h>

gaia::ecs::SystemBuilder RegisterRenderLayerOneSystem(gaia::ecs::World& world);
gaia::ecs::SystemBuilder RegisterRenderLayerTwoSystem(gaia::ecs::World& world);
gaia::ecs::SystemBuilder RegisterRenderLayerThreeSystem(gaia::ecs::World& world);