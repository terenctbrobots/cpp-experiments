#include "Systems/MovementSystem.h"

#include "Components/VelocityComponent.h"
#include "Components/Transform2D.h"

gaia::ecs::SystemBuilder RegisterMovementSystem(gaia::ecs::World& world, float& dt)
{
    return world.system()
        .all<Transform2D&>()
        .all<VelocityComponent>()
        .on_each([&dt](Transform2D& pos, const VelocityComponent& velocity)
        {
            pos.m_X += velocity.m_Direction.x*velocity.m_Speed*dt;
            pos.m_Y += velocity.m_Direction.y*velocity.m_Speed*dt;
        });
}