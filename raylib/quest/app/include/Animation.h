#pragma once

#include "Hash.h"
#include "gaia.h"
#include "raylib.h"
#include "tsl/robin_map.h"

#include <string>

namespace Animation
{
    struct AnimationFrame
    {
        std::vector<Rectangle> m_FrameList;
        float m_FrameDuration;
        u_int m_Frames;
        bool m_Flip;
    };

    struct AnimationData
    {
        float m_Width;
        float m_Height;

        Vector2 m_Offset = Vector2{0, 0};

        uint32_t m_DefaultAnimation;
        tsl::robin_map<uint32_t, Animation::AnimationFrame> m_AnimationList;
    };

    // bool Load(const std::string& fileName, AnimationDataComponent& animationData);
    void SetAnimation(gaia::ecs::World& world, gaia::ecs::Entity entity, const std::string& assetName,
                      const uint32_t animationName = 0);

    const uint32_t MOVE_LEFT = HS("move_left");
    const uint32_t MOVE_RIGHT = HS("move_right");
    const uint32_t MOVE_UP = HS("move_up");
    const uint32_t MOVE_DOWN = HS("move_down");

    const uint32_t IDLE_LEFT = HS("idle_left");
    const uint32_t IDLE_RIGHT = HS("idle_right");
    const uint32_t IDLE_UP = HS("idle_up");
    const uint32_t IDLE_DOWN = HS("idle_down");

    const uint32_t ATTACK_LEFT = HS("attack_left");
    const uint32_t ATTACK_RIGHT = HS("attack_right");
    const uint32_t ATTACK_UP = HS("attack_up");
    const uint32_t ATTACK_DOWN = HS("attack_down");
} // namespace Animation
