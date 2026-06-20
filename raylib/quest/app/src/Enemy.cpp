#include "Enemy.h"

#include "Animation.h"
#include "Components/AnimationComponent.h"
#include "Components/AnimationDataComponent.h"
#include "Components/ImageComponent.h"
#include "Components/LayerComponent.h"
#include "Components/Transform2D.h"
#include "Components/VelocityComponent.h"
#include "TextureManager.h"
#include "spdlog/spdlog.h"

#include <gaia/ecs/id.h>

constexpr float s_Speed = 100.0f;
const std::string s_EnemyTexture = "slime";

gaia::ecs::Entity Enemy::Create(gaia::ecs::World& world, const Vector2& startPosition)
{
    gaia::ecs::Entity entity = world.add();

    world.add<VelocityComponent>(entity, {s_Speed, {0.0f, 0.0f}});
    world.add<LayerTwoComponent>(entity);
    world.add<Transform2D>(entity, {startPosition.x, startPosition.y});

    auto& texture = TextureManager::Load(s_EnemyTexture);

    if (!IsTextureValid(texture.m_Texture))
    {
        spdlog::error("Could not load Enemy Texture");
        return gaia::ecs::EntityBad;
    }

    ImageComponent imageComponent;
    imageComponent.m_Texture = texture.m_Texture;
    imageComponent.m_SrcRect = {0, 0, 64, 64};
    imageComponent.m_TextureKey = s_EnemyTexture;

    world.add<ImageComponent>(entity, std::move(imageComponent));

    AnimationDataComponent animationData;

    if (!Animation::Load(texture.m_DataPath, animationData))
    {
        return gaia::ecs::EntityBad;
    }

    uint32_t defaultAnimation = animationData.m_DefaultAnimation;

    world.add<AnimationComponent>(entity);
    world.add<AnimationDataComponent>(entity, std::move(animationData));

    Animation::SetAnimation(world, entity, defaultAnimation);

    return entity;
}
