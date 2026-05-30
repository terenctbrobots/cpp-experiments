#include "Systems/AnimationSystem.h"

#include "Components/AnimationComponent.h"
#include "Components/AnimationDataComponent.h"
#include "Components/ImageComponent.h"

gaia::ecs::SystemBuilder RegisterAnimationSystem(gaia::ecs::World& world, float& dt)
{
    return world.system()
        .all<ImageComponent&>()
        .all<AnimationComponent&>()
        .all<AnimationDataComponent>()
        .on_each([&dt](ImageComponent& sprite, AnimationComponent& animation, const AnimationDataComponent& animationData)
        {
            animation.m_Timer += dt;

            AnimationFrame frame = animationData.m_AnimationList.at(animation.m_CurrentAnimation);

            if (animation.m_Timer >= frame.m_FrameDuration)
            {
                animation.m_CurrentFrame += 1;

                if (animation.m_CurrentFrame == frame.m_Frames)
                {
                    animation.m_CurrentFrame = 0;
                }

                sprite.m_SrcRect = frame.m_FrameList[animation.m_CurrentFrame];
                sprite.m_Flip = frame.m_Flip;

                animation.m_Timer -= frame.m_FrameDuration;
            }
        });
}