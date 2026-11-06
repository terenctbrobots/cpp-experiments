#pragma once

#include "Animation.h"
#include "raylib.h"

#include <sys/types.h>
#include <vector>

namespace Animation
{
    struct AnimationFrameComponent
    {
        std::vector<Rectangle> m_FrameList;
        float m_FrameDuration;
        u_int32_t m_Frames;
        bool m_Flip;
    };

    inline AnimationFrameComponent ToAnimationFrameComponent(const Animation::AnimationFrame& frame)
    {
        return AnimationFrameComponent{.m_FrameList = frame.m_FrameList,
                                       .m_FrameDuration = frame.m_FrameDuration,
                                       .m_Frames = frame.m_Frames,
                                       .m_Flip = frame.m_Flip};
    }
} // namespace Animation
