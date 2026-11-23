#include "Systems/EnemySystem.h"

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
    void ChooseMoveDestination(Gameplay::EnemyComponent& enemy, Gameplay::VelocityComponent& velocity)
    {
        // Pick a random direction
        int randomDirection = GetRandomValue(0, 3);
        switch (Gameplay::Moving_Left + randomDirection)
        {
            case Gameplay::EEnemyState::Moving_Left:
            {
                enemy.m_Destination.x = -1.0f * GetRandomValue(s_MinMoveDistance, s_MaxMoveDistance);
                velocity.m_Direction = {-1, 0};
                enemy.m_State = Gameplay::EEnemyState::Moving_Left;
                break;
            }
            case Gameplay::EEnemyState::Moving_Right:
            {
                enemy.m_Destination.x = GetRandomValue(s_MinMoveDistance, s_MaxMoveDistance);
                velocity.m_Direction = {1, 0};
                enemy.m_State = Gameplay::EEnemyState::Moving_Right;
                break;
            }
            case Gameplay::EEnemyState::Moving_Down:
            {
                enemy.m_Destination.x = 1.0f * GetRandomValue(s_MinMoveDistance, s_MaxMoveDistance);
                velocity.m_Direction = {0, 1};
                enemy.m_State = Gameplay::EEnemyState::Moving_Down;
                break;
            }
            case Gameplay::EEnemyState::Moving_Up:
            {
                enemy.m_Destination.x = -1.0f * GetRandomValue(s_MinMoveDistance, s_MaxMoveDistance);
                velocity.m_Direction = {0, -1};
                enemy.m_State = Gameplay::EEnemyState::Moving_Up;
                break;
            }
        }
    }
} // namespace

void EnemySystem::Init(gaia::ecs::World& world)
{
    m_Query = world.query()
                  .all<Gameplay::EnemyComponent&>()
                  .all<Gameplay::VelocityComponent&>()
                  .all<const Gameplay::Transform2D>();
}

void EnemySystem::Update(float dt)
{
    m_Query.each(
        [&](gaia::ecs::Entity entity1, Gameplay::EnemyComponent& enemy, Gameplay::VelocityComponent& velocity,
            const Gameplay::Transform2D& pos)
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
                        ChooseMoveDestination(enemy, velocity);
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
