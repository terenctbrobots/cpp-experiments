#include "Systems/CollisionSystem.h"

#include "Components/BoundingBoxComponent.h"
#include "Components/Transform2D.h"
#include "Components/VelocityComponent.h"
#include "Game.h"
#include "raylib.h"
#include "raymath.h"
#include "spdlog/spdlog.h"

void CollisionSystem::Init(gaia::ecs::World& world)
{
    m_Query = world.query()
                  .all<const Transform2D>()
                  .all<Gameplay::BoundingBoxComponent&>()
                  .all<Gameplay::VelocityComponent&>();
}

void CollisionSystem::Update(float dt)
{
    m_Query.each(
        [&](gaia::ecs::Entity entity1, const Transform2D& position1, Gameplay::BoundingBoxComponent& box1,
            Gameplay::VelocityComponent& velocity1)
        {
            const float position1X =
                position1.m_Pos.x + velocity1.m_Direction.x * velocity1.m_Speed * dt + box1.m_Offset.x;
            const float position1Y =
                position1.m_Pos.y + velocity1.m_Direction.x * velocity1.m_Speed * dt + box1.m_Offset.y;
            const Rectangle Rect1 = {position1X, position1Y, box1.m_Width, box1.m_Height};

            m_Query.each(
                [&](gaia::ecs::Entity entity2, const Transform2D& position2, Gameplay::BoundingBoxComponent& box2,
                    Gameplay::VelocityComponent& velocity2)
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
                        spdlog::warn("Collision!");

                        Rectangle overlap = GetCollisionRec(Rect1, Rect2);

                        Vector2 normal = {0, 0};
                        float penetration = 0.0f;

                        if (overlap.width < overlap.height)
                        {
                            penetration = overlap.width;
                            normal.x = (Rect1.x < Rect2.x) ? -1.0f : 1.0f;
                        }
                        else
                        {
                            penetration = overlap.height;
                            normal.y = (Rect1.y < Rect2.y) ? -1.0f : 1.0f;
                        }

                        //     // 4. Position Resolution (Push out proportional to inverse mass)
                        //     float ratioA = a.invMass / totalInvMass;
                        //     float ratioB = b.invMass / totalInvMass;

                        //     a.pos.x += normal.x * penetration * ratioA;
                        //     a.pos.y += normal.y * penetration * ratioA;

                        //     b.pos.x -= normal.x * penetration * ratioB;
                        //     b.pos.y -= normal.y * penetration * ratioB;

                        //     // 5. Velocity Resolution (Inelastic / Momentum transfer)
                        //     Vector2 relVel = { a.vel.x - b.vel.x, a.vel.y - b.vel.y };
                        //     float velAlongNormal = relVel.x * normal.x + relVel.y * normal.y;

                        //     // Do not resolve if objects are moving apart
                        //     if (velAlongNormal > 0.0f) return;

                        //     // Restitution (0.0 = no bounce, 1.0 = completely elastic)
                        //     float restitution = 0.0f;

                        //     // Calculate impulse scalar
                        //     float j = -(1.0f + restitution) * velAlongNormal;
                        //     j /= totalInvMass;

                        //     // Apply impulse along collision normal
                        //     Vector2 impulse = { normal.x * j, normal.y * j };

                        //     a.vel.x += impulse.x * a.invMass;
                        //     a.vel.y += impulse.y * a.invMass;

                        //     b.vel.x -= impulse.x * b.invMass;
                        //     b.vel.y -= impulse.y * b.invMass;

                        // Zeroing the velocity isn't enough as we need to move the entities outside of collision boxes
                        velocity1.m_Direction = {0, 0};
                        velocity2.m_Direction = {0, 0};
                    }
                });
        });

    if (Game::IsDebug())
    {
        m_Query.each(
            [&](const Transform2D& position, Gameplay::BoundingBoxComponent& box, Gameplay::VelocityComponent& velocity)
            {
                const Vector2 newPosition = Vector2Add(position.m_Pos, box.m_Offset);
                box.m_Collision.x = newPosition.x;
                box.m_Collision.y = newPosition.y;
                box.m_Collision.width = box.m_Width;
                box.m_Collision.height = box.m_Height;
            });
    }
}
