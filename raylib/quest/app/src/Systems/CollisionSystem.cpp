#include "Systems/CollisionSystem.h"

#include "Components/BoundingBoxComponent.h"
#include "Components/Transform2D.h"
#include "Components/VelocityComponent.h"

#include <raymath.h>

void CollisionSystem::Init(gaia::ecs::World& world)
{
    m_Query = world.query().all<const Transform2D>().all<Game::BoundingBoxComponent&>().all<VelocityComponent&>();
}

void CollisionSystem::Update(float dt)
{
    m_Query.each(
        [dt](const Transform2D& position, Game::BoundingBoxComponent& box, VelocityComponent& velocity)
        {
            const Vector2 newPosition = Vector2Add(position.m_Pos, box.m_Offset);
            box.m_Collision.x = newPosition.x;
            box.m_Collision.y = newPosition.y;
            box.m_Collision.width = box.m_Width;
            box.m_Collision.height = box.m_Height;
        });
}
