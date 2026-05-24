
#include "Player.h"

#include "Animation.h"
#include "Components/AnimationDataComponent.h"
#include "Components/AnimationComponent.h"
#include "Components/Transform2D.h"
#include "Components/VelocityComponent.h"
#include "Components/SpriteComponent.h"
#include "spdlog/spdlog.h"

const float speed = 100.0f;

gaia::ecs::Entity Player::Create(gaia::ecs::World& world)
{
    gaia::ecs::Entity entity  = world.add();

    world.add<VelocityComponent>(entity, {speed, {0.0f,0.0f}});

    world.add<Transform2D>(entity, {0.0f,0.0f});
    Texture2D playerTexture = LoadTexture("./assets/characters/player.png");

    if (playerTexture.id <= 0)
    {
        spdlog::error("Could not load Player Texture");
        return gaia::ecs::EntityBad;
    }

    world.add<SpriteComponent>(entity, {std::move(playerTexture), {0,0,64,64}});

    AnimationDataComponent animationData;
    
    if (!Animation::Load("./assets/characters/player.json", animationData))
    {
        return gaia::ecs::EntityBad;
    }

    std::string defaultAnimation = animationData.m_DefaultAnimation;

    world.add<AnimationComponent>(entity);
    world.add<AnimationDataComponent>(entity, std::move(animationData));

    Animation::SetAnimation(world, entity, defaultAnimation);

    return entity;
}