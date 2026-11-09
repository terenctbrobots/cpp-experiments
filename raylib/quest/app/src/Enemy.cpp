#include "Enemy.h"

#include "Animation.h"
#include "AssetManager.h"
#include "Components/AnimationComponent.h"
#include "Components/AnimationFrameComponent.h"
#include "Components/BoundingBoxComponent.h"
#include "Components/EnemyComponent.h"
#include "Components/ImageComponent.h"
#include "Components/LayerComponent.h"
#include "Components/Transform2D.h"
#include "Components/VelocityComponent.h"
#include "spdlog/spdlog.h"

constexpr float s_Speed = 100.0f;
const std::string s_EnemyTexture = "slime";

gaia::ecs::Entity Enemy::Create(gaia::ecs::World& world, const Vector2& startPosition)
{
    gaia::ecs::Entity entity = world.add();

    world.add<Game::EnemyComponent>(entity);
    world.add<VelocityComponent>(entity, {s_Speed, {0.0f, 0.0f}});
    world.add<Render::LayerTwoComponent>(entity);
    world.add<Transform2D>(entity, {startPosition.x, startPosition.y});

    Texture2D enemyTexture = AssetManager::GetTexture(AssetManager::s_EnemyAsset);

    if (!IsTextureValid(enemyTexture))
    {
        spdlog::error("Could not load Enemy Texture");
        return gaia::ecs::EntityBad;
    }

    Animation::ImageComponent imageComponent;
    imageComponent.m_Texture = enemyTexture;
    imageComponent.m_SrcRect = {0, 0, 32, 32};

    world.add<Animation::ImageComponent>(entity, std::move(imageComponent));

    world.add<Animation::AnimationFrameComponent>(entity);
    world.add<Animation::AnimationComponent>(entity);

    Game::BoundingBoxComponent boundingBoxComponent;
    boundingBoxComponent.m_Offset = {-7, -3};
    boundingBoxComponent.m_Width = 14;
    boundingBoxComponent.m_Height = 12;

    world.add<Game::BoundingBoxComponent>(entity, std::move(boundingBoxComponent));

    Animation::SetAnimation(world, entity, AssetManager::s_EnemyAsset);

    return entity;
}
