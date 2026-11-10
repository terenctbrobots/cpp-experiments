
#include "Player.h"

#include "Animation.h"
#include "AssetManager.h"
#include "Components/AnimationComponent.h"
#include "Components/AnimationFrameComponent.h"
#include "Components/BoundingBoxComponent.h"
#include "Components/ImageComponent.h"
#include "Components/LayerComponent.h"
#include "Components/PlayerComponent.h"
#include "Components/Transform2D.h"
#include "Components/VelocityComponent.h"
#include "raylib.h"
#include "spdlog/spdlog.h"

constexpr float s_Speed = 100.0f;

gaia::ecs::Entity Player::Create(gaia::ecs::World& world)
{
    gaia::ecs::Entity entity = world.add();

    world.add<Gameplay::PlayerComponent>(entity);
    world.add<Gameplay::VelocityComponent>(entity, {s_Speed, {0.0f, 0.0f}});
    world.add<Render::LayerTwoComponent>(entity);
    world.add<Transform2D>(entity, {0.0f, 0.0f});

    Texture2D playerTexture = AssetManager::GetTexture(AssetManager::s_PlayerAsset);
    if (!IsTextureValid(playerTexture))
    {
        spdlog::error("Could not load Player Texture");
        return gaia::ecs::EntityBad;
    }

    Animation::ImageComponent imageComponent;
    imageComponent.m_Texture = playerTexture;
    imageComponent.m_SrcRect = {0, 0, 64, 64};

    world.add<Animation::ImageComponent>(entity, std::move(imageComponent));

    world.add<Animation::AnimationFrameComponent>(entity);
    world.add<Animation::AnimationComponent>(entity);

    Gameplay::BoundingBoxComponent boundingBoxComponent;
    boundingBoxComponent.m_Offset = {-5, -13};
    boundingBoxComponent.m_Width = 12;
    boundingBoxComponent.m_Height = 18;
    boundingBoxComponent.m_InvMass = 0.5f;

    world.add<Gameplay::BoundingBoxComponent>(entity, std::move(boundingBoxComponent));

    Animation::SetAnimation(world, entity, AssetManager::s_PlayerAsset);

    return entity;
}

void Player::Movement(gaia::ecs::World& world, gaia::ecs::Entity& player, Vector2 direction, uint32_t animationName)
{
    auto velocity = world.set<Gameplay::VelocityComponent>(player);
    velocity.m_Direction = direction;

    auto& animation = world.get<Animation::AnimationComponent>(player);

    if (animation.m_CurrentAnimation != animationName)
    {
        Animation::SetAnimation(world, player, AssetManager::s_PlayerAsset, animationName);
    }
}

void Player::Idle(gaia::ecs::World& world, gaia::ecs::Entity& player)
{
    auto velocity = world.set<Gameplay::VelocityComponent>(player);
    velocity.m_Direction = {0.0f, 0.0f};

    auto& animation = world.get<Animation::AnimationComponent>(player);

    if (animation.m_CurrentAnimation == Animation::MOVE_LEFT || animation.m_CurrentAnimation == Animation::ATTACK_LEFT)
    {
        Animation::SetAnimation(world, player, AssetManager::s_PlayerAsset, Animation::IDLE_LEFT);
    }

    if (animation.m_CurrentAnimation == Animation::MOVE_RIGHT ||
        animation.m_CurrentAnimation == Animation::ATTACK_RIGHT)
    {
        Animation::SetAnimation(world, player, AssetManager::s_PlayerAsset, Animation::IDLE_RIGHT);
    }

    if (animation.m_CurrentAnimation == Animation::MOVE_DOWN || animation.m_CurrentAnimation == Animation::ATTACK_DOWN)
    {
        Animation::SetAnimation(world, player, AssetManager::s_PlayerAsset, Animation::IDLE_DOWN);
    }

    if (animation.m_CurrentAnimation == Animation::MOVE_UP || animation.m_CurrentAnimation == Animation::ATTACK_UP)
    {
        Animation::SetAnimation(world, player, AssetManager::s_PlayerAsset, Animation::IDLE_UP);
    }
}

void Player::Attack(gaia::ecs::World& world, gaia::ecs::Entity& player)
{
    auto& animation = world.get<Animation::AnimationComponent>(player);

    if (animation.m_CurrentAnimation == Animation::IDLE_LEFT || animation.m_CurrentAnimation == Animation::MOVE_LEFT)
    {
        Animation::SetAnimation(world, player, AssetManager::s_PlayerAsset, Animation::ATTACK_LEFT);
    }

    if (animation.m_CurrentAnimation == Animation::IDLE_RIGHT || animation.m_CurrentAnimation == Animation::MOVE_RIGHT)
    {
        Animation::SetAnimation(world, player, AssetManager::s_PlayerAsset, Animation::ATTACK_RIGHT);
    }

    if (animation.m_CurrentAnimation == Animation::IDLE_DOWN || animation.m_CurrentAnimation == Animation::MOVE_DOWN)
    {
        Animation::SetAnimation(world, player, AssetManager::s_PlayerAsset, Animation::ATTACK_DOWN);
    }

    if (animation.m_CurrentAnimation == Animation::IDLE_UP || animation.m_CurrentAnimation == Animation::MOVE_UP)
    {
        Animation::SetAnimation(world, player, AssetManager::s_PlayerAsset, Animation::ATTACK_UP);
    }
}

Vector2 Player::GetPosition(gaia::ecs::World& world, gaia::ecs::Entity& player)
{
    return world.get<Transform2D>(player).m_Pos;
}

void Player::SetPosition(gaia::ecs::World& world, gaia::ecs::Entity& player, const Vector2& position)
{
    world.set<Transform2D>(player).m_Pos = position;
}
