#include "Animation.h"

#include "AssetManager.h"
#include "Components/AnimationComponent.h"
#include "Components/AnimationFrameComponent.h"
#include "Components/ImageComponent.h"
#include "spdlog/spdlog.h"

#include <cstdint>

void Animation::SetAnimation(gaia::ecs::World& world, gaia::ecs::Entity entity, const std::string& assetName,
                             const uint32_t animationName)
{
    auto animationFrame = world.set<AnimationFrameComponent>(entity);
    auto sprite = world.set<Animation::ImageComponent>(entity);
    auto animation = world.set<Animation::AnimationComponent>(entity);

    UpdateAnimation(animationFrame, sprite, animation, assetName, animationName);
}

void Animation::UpdateAnimation(Animation::AnimationFrameComponent& animationFrame, Animation::ImageComponent& sprite,
                                Animation::AnimationComponent& animation, const std::string& assetName,
                                const uint32_t animationName)
{
    const Animation::AnimationData* animationData = AssetManager::GetAnimation(assetName);

    if (animationData == nullptr)
    {
        spdlog::error("Could not find animation {}", assetName);
        return;
    }
    uint32_t selectedAnimation = animationName;

    if (selectedAnimation == 0)
    {
        selectedAnimation = animationData->m_DefaultAnimation;
    }

    Animation::AnimationFrame animationFrameData = animationData->m_AnimationList.at(selectedAnimation);
    animationFrame = Animation::ToAnimationFrameComponent(animationFrameData);

    sprite.m_SrcRect = animationFrameData.m_FrameList[0];
    sprite.m_Offset = animationData->m_Offset;

    animation.m_CurrentAnimation = selectedAnimation;
    animation.m_CurrentFrame = 0;
    animation.m_Timer = animationFrameData.m_FrameDuration;
}
