
#include "Player.h"

#include "Animation.h"
#include "Components/AnimationComponent.h"
#include "Components/AnimationDataComponent.h"
#include "Components/ImageComponent.h"
#include "Components/LayerComponent.h"
#include "Components/Transform2D.h"
#include "Components/VelocityComponent.h"
#include "TextureManager.h"
#include "spdlog/spdlog.h"

#include <raylib.h>

constexpr float s_Speed = 100.0f;
const std::string s_PlayerTexture = "player";

gaia::ecs::Entity Player::Create(gaia::ecs::World& world)
{
    gaia::ecs::Entity entity = world.add();

    world.add<VelocityComponent>(entity, {s_Speed, {0.0f, 0.0f}});

    world.add<LayerTwoComponent>(entity);

    world.add<Transform2D>(entity, {0.0f, 0.0f});

    auto& texture = TextureManager::Load(s_PlayerTexture);

    if (!IsTextureValid(texture.m_Texture))
    {
        spdlog::error("Could not load Player Texture");
        return gaia::ecs::EntityBad;
    }

    ImageComponent imageComponent;
    imageComponent.m_Texture = texture.m_Texture;
    imageComponent.m_SrcRect = {0, 0, 64, 64};
    imageComponent.m_TextureKey = s_PlayerTexture;

    world.add<ImageComponent>(entity, std::move(imageComponent));

    AnimationDataComponent animationData;

    if (!Animation::Load("./assets/characters/player.json", animationData))
    {
        return gaia::ecs::EntityBad;
    }

    uint32_t defaultAnimation = animationData.m_DefaultAnimation;

    world.add<AnimationComponent>(entity);
    world.add<AnimationDataComponent>(entity, std::move(animationData));

    Animation::SetAnimation(world, entity, defaultAnimation);

    return entity;
}

void Player::Movement(gaia::ecs::World& world, gaia::ecs::Entity& player, Vector2 direction, uint32_t animationName)
{
    auto& velocity = world.set<VelocityComponent>(player);
    velocity.m_Direction = direction;

    auto& animation = world.get<AnimationComponent>(player);

    if (animation.m_CurrentAnimation != animationName)
    {
        Animation::SetAnimation(world, player, animationName);
    }
}

void Player::Idle(gaia::ecs::World& world, gaia::ecs::Entity& player)
{
    auto& velocity = world.set<VelocityComponent>(player);
    velocity.m_Direction = {0.0f, 0.0f};

    auto& animation = world.get<AnimationComponent>(player);

    if (animation.m_CurrentAnimation == Animation::MOVE_LEFT || animation.m_CurrentAnimation == Animation::ATTACK_LEFT)
    {
        Animation::SetAnimation(world, player, Animation::IDLE_LEFT);
    }

    if (animation.m_CurrentAnimation == Animation::MOVE_RIGHT ||
        animation.m_CurrentAnimation == Animation::ATTACK_RIGHT)
    {
        Animation::SetAnimation(world, player, Animation::IDLE_RIGHT);
    }

    if (animation.m_CurrentAnimation == Animation::MOVE_DOWN || animation.m_CurrentAnimation == Animation::ATTACK_DOWN)
    {
        Animation::SetAnimation(world, player, Animation::IDLE_DOWN);
    }

    if (animation.m_CurrentAnimation == Animation::MOVE_UP || animation.m_CurrentAnimation == Animation::ATTACK_UP)
    {
        Animation::SetAnimation(world, player, Animation::IDLE_UP);
    }
}

void Player::Attack(gaia::ecs::World& world, gaia::ecs::Entity& player)
{
    auto& animation = world.get<AnimationComponent>(player);

    if (animation.m_CurrentAnimation == Animation::IDLE_LEFT || animation.m_CurrentAnimation == Animation::MOVE_LEFT)
    {
        Animation::SetAnimation(world, player, Animation::ATTACK_LEFT);
    }

    if (animation.m_CurrentAnimation == Animation::IDLE_RIGHT || animation.m_CurrentAnimation == Animation::MOVE_RIGHT)
    {
        Animation::SetAnimation(world, player, Animation::ATTACK_RIGHT);
    }

    if (animation.m_CurrentAnimation == Animation::IDLE_DOWN || animation.m_CurrentAnimation == Animation::MOVE_DOWN)
    {
        Animation::SetAnimation(world, player, Animation::ATTACK_DOWN);
    }

    if (animation.m_CurrentAnimation == Animation::IDLE_UP || animation.m_CurrentAnimation == Animation::MOVE_UP)
    {
        Animation::SetAnimation(world, player, Animation::ATTACK_UP);
    }
}

Vector2 Player::GetPosition(gaia::ecs::World& world, gaia::ecs::Entity& player)
{
    return world.get<Transform2D>(player).m_Pos;
}

void Player::SetPosition(gaia::ecs::World& world, gaia::ecs::Entity& player, const Vector2& position)
{
    auto& transform = world.set<Transform2D>(player);
    transform.m_Pos = position;
}
