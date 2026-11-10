#include "Systems/CollisionSystem.h"

#include "Components/BoundingBoxComponent.h"
#include "Components/Transform2D.h"
#include "Components/VelocityComponent.h"

#include <raylib.h>
#include <raymath.h>

void CollisionSystem::Init(gaia::ecs::World& world)
{
    m_Query = world.query().all<const Transform2D>().all<Game::BoundingBoxComponent&>().all<VelocityComponent&>();
}

void CollisionSystem::Update(float dt)
{
    m_Query.each(
        [&](gaia::ecs::Entity entity1, const Transform2D& position1, Game::BoundingBoxComponent& box1,
            VelocityComponent& velocity1)
        {
            const float position1X =
                position1.m_Pos.x + velocity1.m_Direction.x * velocity1.m_Speed * dt + box1.m_Offset.x;
            const float position1Y =
                position1.m_Pos.y + velocity1.m_Direction.x * velocity1.m_Speed * dt + box1.m_Offset.y;
            const Rectangle Rect1 = {position1X, position1Y, box1.m_Width, box1.m_Height};

            m_Query.each(
                [&](gaia::ecs::Entity entity2, const Transform2D& position2, Game::BoundingBoxComponent& box2,
                    VelocityComponent& velocity2)
                {
                    if (entity1 == entity2)
                    {
                        return;
                    }

                    const float position2X =
                        position2.m_Pos.x + velocity2.m_Direction.x * velocity2.m_Speed * dt + box2.m_Offset.x;
                    const float position2Y =
                        position2.m_Pos.y + velocity2.m_Direction.x * velocity2.m_Speed * dt + box2.m_Offset.y;
                    const Rectangle Rect2 = {position2X, position2Y, box2.m_Width, box2.m_Height};

                    if (CheckCollisionRecs(Rect1, Rect2))
                    {
                        // Collision
                        velocity1.m_Direction = {0, 0};
                        velocity2.m_Direction = {0, 0};
                    }
                });
            // const Vector2 newPosition = Vector2Add(position.m_Pos, box.m_Offset);
            // box.m_Collision.x = newPosition.x;
            // box.m_Collision.y = newPosition.y;
            // box.m_Collision.width = box.m_Width;
            // box.m_Collision.height = box.m_Height;
        });
}
