
#include "Player.h"

#include "Components/Transform2D.h"
#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "spdlog/spdlog.h"

bool Player::Create(gaia::ecs::World& world)
{
    gaia::ecs::Entity entity  = world.add();

    world.add<PlayerComponent>(entity);

    world.add<Transform2D>(entity, {0.0f,0.0f});
    Texture2D playerTexture = LoadTexture("./assets/characters/player.png");

    if (playerTexture.id <= 0)
    {
        spdlog::error("Could not load Player Texture");
        return false;
    }

    world.add<SpriteComponent>(entity, {std::move(playerTexture), {0,0,64,64}});

    return true;
}

void Player::Move(gaia::ecs::World& world, float speed, float dt, float x, float y)
{
    gaia::ecs::Query q = world.query()
        .all<Transform2D&>()
        .all<PlayerComponent>();

    q.each([=] (Transform2D& pos)
    {
        pos.m_X += x*dt*speed;
        pos.m_Y += y*dt*speed;
    });

}