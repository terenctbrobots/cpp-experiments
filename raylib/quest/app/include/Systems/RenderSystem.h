#pragma once

#include <gaia.h>

struct RenderSystem
{
    gaia::ecs::Query m_QueryLayerOne;
    gaia::ecs::Query m_QueryLayerTwo;
    gaia::ecs::Query m_QueryLayerThree;

    bool m_Debug = false;

    void Init(gaia::ecs::World& world);
    void Update();
    void ToggleDebug(gaia::ecs::World& world);
};
