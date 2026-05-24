#include "Systems/AnimationSystem.h"

#include "Components/AnimationComponent.h"
#include "Components/AnimationDataComponent.h"
#include "Components/SpriteComponent.h"

gaia::ecs::SystemBuilder RegisterAnimationSystem(gaia::ecs::World& world, float& dt)
{
    return world.system()
        .all<SpriteComponent&>()
        .all<AnimationComponent&>()
        .all<AnimationDataComponent&>()
        .on_each([&dt](SpriteComponent& sprite, AnimationComponent& animation, const AnimationDataComponent& animationData)
        {
            animation.m_Timer += dt;

            AnimationFrame frame = animationData.m_AnimationList.at(animation.m_CurrentAnimation);


            // pos.m_X += velocity.m_Direction.x*velocity.m_Speed*dt;
            // pos.m_Y += velocity.m_Direction.y*velocity.m_Speed*dt;
        });
}