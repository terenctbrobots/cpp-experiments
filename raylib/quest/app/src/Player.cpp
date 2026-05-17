
#include "Player.h"

#include "Components/Transform2D.h"
#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "spdlog/spdlog.h"

const float speed = 100.0f;

gaia::ecs::Entity Player::Create(gaia::ecs::World& world)
{
    gaia::ecs::Entity entity  = world.add();

    world.add<PlayerComponent>(entity);

    world.add<Transform2D>(entity, {0.0f,0.0f});
    Texture2D playerTexture = LoadTexture("./assets/characters/player.png");

    if (playerTexture.id <= 0)
    {
        spdlog::error("Could not load Player Texture");
        return gaia::ecs::EntityBad;
    }

    world.add<SpriteComponent>(entity, {std::move(playerTexture), {0,0,64,64}});

    return entity;
}