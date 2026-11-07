#include "Systems/AnimationSystem.h"

#include "Components/AnimationComponent.h"
#include "Components/AnimationFrameComponent.h"
#include "Components/ImageComponent.h"

void AnimationSystem::Init(gaia::ecs::World& world)
{
    m_Query = world.query()
                  .all<Animation::ImageComponent&>()
                  .all<Animation::AnimationComponent&>()
                  .all<const Animation::AnimationFrameComponent>();
}

void AnimationSystem::Update(float& dt)
{
    m_Query.each(
        [&dt](Animation::ImageComponent& sprite, Animation::AnimationComponent& animation,
              const Animation::AnimationFrameComponent& animationFrame)
        {
            animation.m_Timer += dt;

            if (animation.m_Timer >= animationFrame.m_FrameDuration)
            {
                animation.m_CurrentFrame += 1;
                animation.m_Timer -= animationFrame.m_FrameDuration;

                if (animation.m_CurrentFrame >= animationFrame.m_Frames)
                {
                    animation.m_CurrentFrame = 0;
                }

                sprite.m_SrcRect = animationFrame.m_FrameList[animation.m_CurrentFrame];
                sprite.m_Flip = animationFrame.m_Flip;
            }
        });
}
