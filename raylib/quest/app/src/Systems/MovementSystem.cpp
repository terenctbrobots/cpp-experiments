#include "Systems/MovementSystem.h"

#include "Components/Transform2D.h"
#include "Components/VelocityComponent.h"

void MovementSystem::Init(gaia::ecs::World& world)
{
    m_Query = world.query().all<Transform2D&>().all<const VelocityComponent>();
}

void MovementSystem::Update(float dt)
{
    m_Query.each(
        [dt](Transform2D& pos, const VelocityComponent& velocity)
        {
            const float velocityX = velocity.m_Direction.x * velocity.m_Speed * dt;
            pos.m_Pos.x += velocityX;

            const float velocityY = velocity.m_Direction.y * velocity.m_Speed * dt;
            pos.m_Pos.y += velocityY;
        });
}
