#pragma once

#include <gaia.h>

struct RenderSystem
{
    gaia::ecs::Query m_QueryLayerOne;
    gaia::ecs::Query m_QueryLayerTwo;
    gaia::ecs::Query m_QueryLayerThree;

    void Init(gaia::ecs::World& world);
    void Update();
};