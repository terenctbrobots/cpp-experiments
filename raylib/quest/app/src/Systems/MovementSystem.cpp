#include "Systems/MovementSystem.h"

#include "Components/PlayerComponent.h"
#include "Components/Transform2D.h"

const float speed = 100.0f;

gaia::ecs::SystemBuilder RegisterMovementSystem(gaia::ecs::World& world)
{
    return world.system()
        .all<Transform2D&>()
        .all<PlayerComponent>()
        .on_each([](Transform2D& pos, const PlayerComponent& player)
        {
            pos.m_X += player.m_DirectionX*speed*player.m_deltaTime;
            pos.m_Y += player.m_DirectionY*speed*player.m_deltaTime;
        });
}