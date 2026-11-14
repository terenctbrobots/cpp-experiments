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
                  .all<const Gameplay::Transform2D>()
                  .all<Gameplay::BoundingBoxComponent&>()
                  .all<Gameplay::VelocityComponent&>();
}

void CollisionSystem::Update(float dt)
{
    m_Query.each(
        [&](gaia::ecs::Entity entity1, const Gameplay::Transform2D& position1, Gameplay::BoundingBoxComponent& box1,
            Gameplay::VelocityComponent& velocity1)
        {
            const float velocity1X = velocity1.m_Direction.x * velocity1.m_Speed * dt;
            float position1X = position1.m_Pos.x + box1.m_Offset.x + velocity1X;
            const float velocity1Y = velocity1.m_Direction.y * velocity1.m_Speed * dt;
            float position1Y = position1.m_Pos.y + box1.m_Offset.y + velocity1Y;
            const Rectangle Rect1 = {position1X, position1Y, box1.m_Width, box1.m_Height};

            m_Query.each(
                [&](gaia::ecs::Entity entity2, const Gameplay::Transform2D& position2,
                    Gameplay::BoundingBoxComponent& box2, Gameplay::VelocityComponent& velocity2)
                {
                    if (entity1 == entity2)
                    {
                        return;
                    }

                    const float velocity2X = velocity2.m_Direction.x * velocity2.m_Speed * dt;
                    float position2X = position2.m_Pos.x + box2.m_Offset.x + velocity2X;
                    const float velocity2Y = velocity2.m_Direction.y * velocity2.m_Speed * dt;
                    float position2Y = position2.m_Pos.y + box2.m_Offset.y + velocity2Y;
                    const Rectangle Rect2 = {position2X, position2Y, box2.m_Width, box2.m_Height};

                    if (CheckCollisionRecs(Rect1, Rect2))
                    {
                        spdlog::warn("Collision!");

                        // Rectangle overlap = GetCollisionRec(Rect1, Rect2);

                        // Vector2 normal = {0, 0};
                        // float penetration = 0.0f;
                        // const float totalInvMass = box1.m_InvMass + box2.m_InvMass;

                        // if (overlap.width < overlap.height)
                        // {
                        //     penetration = overlap.width;
                        //     normal.x = (Rect1.x < Rect2.x) ? -1.0f : 1.0f;
                        // }
                        // else
                        // {
                        //     penetration = overlap.height;
                        //     normal.y = (Rect1.y < Rect2.y) ? -1.0f : 1.0f;
                        // }

                        // // Position Resolution (Push out proportional to inverse mass)
                        // const float ratio1 = box1.m_InvMass / totalInvMass;
                        // float ratio2 = box2.m_InvMass / totalInvMass;

                        // position1X += normal.x * penetration * ratio1;
                        // position1Y += normal.y + penetration * ratio1;

                        // position2X -= normal.x * penetration * ratio2;
                        // position2Y -= normal.y * penetration * ratio2;

                        // Velocity Resolution (Inelastic / Momentum transfer)
                        // Vector2 relVel = { a.vel.x - b.vel.x, a.vel.y - b.vel.y };
                        //  float velAlongNormal = relVel.x * normal.x + relVel.y * normal.y;

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

                        // Zeroing the velocity may not be enough as we need to move the entities outside of collision
                        // boxes
                        if (velocity1X != 0 || velocity1Y != 0)
                        {
                            velocity1.m_Direction = {0, 0};
                        }

                        if (velocity2X != 0 || velocity2Y != 0)
                        {
                            velocity2.m_Direction = {0, 0};
                        }
                    }
                });
        });

    if (Game::IsDebug())
    {
        m_Query.each(
            [&](const Gameplay::Transform2D& position, Gameplay::BoundingBoxComponent& box,
                Gameplay::VelocityComponent& velocity)
            {
                const Vector2 newPosition = Vector2Add(position.m_Pos, box.m_Offset);
                box.m_Collision.x = newPosition.x;
                box.m_Collision.y = newPosition.y;
                box.m_Collision.width = box.m_Width;
                box.m_Collision.height = box.m_Height;
            });
    }
}
