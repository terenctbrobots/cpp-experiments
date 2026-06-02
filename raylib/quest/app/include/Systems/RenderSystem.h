#pragma once

#include <gaia.h>

struct RenderSystem
{
    gaia::ecs::Query queryLayerOne;
    gaia::ecs::Query queryLayerTwo;
    gaia::ecs::Query queryLayerThree;

    void Init(gaia::ecs::World& world);
    void Update();
};