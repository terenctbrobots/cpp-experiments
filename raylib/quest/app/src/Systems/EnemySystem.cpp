#include "Systems/EnemySystem.h"

#include "Components/AnimationComponent.h"
#include "Components/EnemyComponent.h"
#include "Components/Transform2D.h"
#include "Components/VelocityComponent.h"
#include "spdlog/spdlog.h"

#include <raylib.h>
#include <raymath.h>

namespace
{
    constexpr float s_MoveRadius = 150.0f;
    constexpr float s_MinMoveDistance = 50.0f;
    constexpr float s_MaxMoveDistance = 100.0f;
    constexpr float s_CloseThreshold = 10.0f;
} // namespace

namespace
{
    void ChooseMoveDestination(Gameplay::EnemyComponent& enemy, Gameplay::VelocityComponent& velocity,
                               Animation::AnimationComponent& animation, const Gameplay::Transform2D& pos)
    {
        // Pick a random direction
        int randomDirection = GetRandomValue(0, 3);
        switch (Gameplay::Moving_Left + randomDirection)
        {
            case Gameplay::EEnemyState::Moving_Left:
            {
                enemy.m_Destination.x = pos.m_Pos.x + -1.0f * GetRandomValue(s_MinMoveDistance, s_MaxMoveDistance);
                enemy.m_Destination.y = pos.m_Pos.y;
                velocity.m_Direction = {-1, 0};
                enemy.m_State = Gameplay::EEnemyState::Moving_Left;
                break;
            }
            case Gameplay::EEnemyState::Moving_Right:
            {
                enemy.m_Destination.x = pos.m_Pos.x + GetRandomValue(s_MinMoveDistance, s_MaxMoveDistance);
                enemy.m_Destination.y = pos.m_Pos.y;
                velocity.m_Direction = {1, 0};
                enemy.m_State = Gameplay::EEnemyState::Moving_Right;
                break;
            }
            case Gameplay::EEnemyState::Moving_Down:
            {
                enemy.m_Destination.x = pos.m_Pos.x;
                enemy.m_Destination.y = pos.m_Pos.y + GetRandomValue(s_MinMoveDistance, s_MaxMoveDistance);
                velocity.m_Direction = {0, 1};
                enemy.m_State = Gameplay::EEnemyState::Moving_Down;
                break;
            }
            case Gameplay::EEnemyState::Moving_Up:
            {
                enemy.m_Destination.x = pos.m_Pos.x;
                enemy.m_Destination.y = pos.m_Pos.y + -1.0f * GetRandomValue(s_MinMoveDistance, s_MaxMoveDistance);
                velocity.m_Direction = {0, -1};
                enemy.m_State = Gameplay::EEnemyState::Moving_Up;
                break;
            }
        }
        spdlog::info("Chose destination {:.0f} {:.0f}", enemy.m_Destination.x, enemy.m_Destination.y);
    }
} // namespace

void EnemySystem::Init(gaia::ecs::World& world)
{
    m_Query = world.query()
                  .all<Gameplay::EnemyComponent&>()
                  .all<Gameplay::VelocityComponent&>()
                  .all<Animation::AnimationComponent&>()
                  .all<const Gameplay::Transform2D>();
}

void EnemySystem::Update(float dt)
{
    m_Query.each(
        [&](gaia::ecs::Entity entity1, Gameplay::EnemyComponent& enemy, Gameplay::VelocityComponent& velocity,
            Animation::AnimationComponent& animation, const Gameplay::Transform2D& pos)
        {
            switch (enemy.m_State)
            {
                case Gameplay::EEnemyState::Start_Up:
                {
                    enemy.m_SpawnPosition = pos.m_Pos;
                    enemy.m_State = Gameplay::EEnemyState::Idle;
                    break;
                }
                case Gameplay::EEnemyState::Idle:
                {
                    if (enemy.m_Destination.x == 0 && enemy.m_Destination.y == 0)
                    {
                        ChooseMoveDestination(enemy, velocity, animation, pos);
                    }
                    break;
                }
                case Gameplay::EEnemyState::Moving_Left:
                case Gameplay::EEnemyState::Moving_Down:
                case Gameplay::EEnemyState::Moving_Up:
                case Gameplay::EEnemyState::Moving_Right:
                {
                    if (Vector2DistanceSqr(pos.m_Pos, enemy.m_Destination) <= s_CloseThreshold * s_CloseThreshold)
                    {
                        enemy.m_Destination = {0, 0};
                        enemy.m_State = Gameplay::EEnemyState::Idle;
                    }
                    break;
                }
                default:
                    spdlog::info("Unhandled Enemy State");
            }
        });
}
