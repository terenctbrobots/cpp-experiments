#include "Animation.h"

#include "AssetManager.h"
#include "Components/AnimationComponent.h"
#include "Components/AnimationFrameComponent.h"
#include "Components/ImageComponent.h"

#include <cstdint>
#include <nlohmann/json.hpp>

void Animation::SetAnimation(gaia::ecs::World& world, gaia::ecs::Entity entity, const std::string& assetName,
                             const uint32_t animationName)
{

    if (const Animation::AnimationData* animationData = AssetManager::GetAnimation(assetName))
    {
        uint32_t selectedAnimation = animationName;

        if (selectedAnimation == 0)
        {
            selectedAnimation = animationData->m_DefaultAnimation;
        }

        Animation::AnimationFrame animationFrame = animationData->m_AnimationList.at(selectedAnimation);
        world.set<AnimationFrameComponent>(entity) = Animation::ToAnimationFrameComponent(animationFrame);

        auto sprite = world.get<ImageComponent>(entity);
        sprite.m_SrcRect = animationFrame.m_FrameList[0];
        sprite.m_Offset = animationData->m_Offset;

        auto animation = world.get<Animation::AnimationComponent>(entity);
        animation.m_CurrentAnimation = animationName;
        animation.m_CurrentFrame = 0;
        animation.m_Timer = animationFrame.m_FrameDuration;
    }
}
