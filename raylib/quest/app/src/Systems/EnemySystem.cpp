#include "Systems/EnemySystem.h"

#include "Animation.h"
#include "AssetManager.h"
#include "Components/AnimationComponent.h"
#include "Components/AnimationFrameComponent.h"
#include "Components/EnemyComponent.h"
#include "Components/ImageComponent.h"
#include "Components/Transform2D.h"
#include "Components/VelocityComponent.h"
#include "spdlog/spdlog.h"

#include <raylib.h>
#include <raymath.h>

namespace
{
    constexpr float s_MoveRadius = 150.0f; // Must be non-zero or will will get divide by zero
    constexpr float s_MinMoveDistance = 50.0f;
    constexpr float s_MaxMoveDistance = 100.0f;
    constexpr float s_CloseThreshold = 10.0f;
    constexpr float s_EnemyBiasStrength = 1.0f;

    // Make sure this is the same as the directions
    constexpr std::array<Vector2, 4> s_Dirs = {{
        {0.0f, -1.0f}, // Up
        {0.0f, 1.0f},  // Down
        {-1.0f, 0.0f}, // Left
        {1.0f, 0.0f}   // Right
    }};
} // namespace

namespace
{
    Gameplay::EEnemyState PickRandomDirection(const Gameplay::EnemyComponent& enemy, const Gameplay::Transform2D& pos)
    {
        Vector2 toHome = Vector2Subtract(enemy.m_SpawnPosition, pos.m_Pos);
        float dist = Vector2Length(toHome);

        // 0.0 at spawn -> 1.0 at or beyond radius
        float distanceRatio = Clamp(dist / s_MoveRadius, 0.0f, 1.0f);

        Vector2 homeDir = (dist > 0.0001f) ? Vector2Scale(toHome, 1.0f / dist) : Vector2{0.0f, 0.0f};

        std::array<float, 4> weights{};
        float totalWeight = 0.0f;

        for (int i = 0; i < 4; ++i)
        {
            // Positive when dirs[i] points toward spawnPos, negative away from it
            float alignment = Vector2DotProduct(s_Dirs[i], homeDir);
            float w = 1.0f + s_EnemyBiasStrength * distanceRatio * alignment;
            if (w < 0.05f)
            {
                w = 0.05f; // Keep a tiny chance even when pushed far past maxRadius
            }
            weights[i] = w;
            totalWeight += w;
        }

        // Roll a float in [0.0f, totalWeight)
        float roll = static_cast<float>(GetRandomValue(0, 10000)) / 10000.0f * totalWeight;
        float cumulative = 0.0f;

        for (int i = 0; i < 4; ++i)
        {
            cumulative += weights[i];
            if (roll < cumulative)
            {
                return static_cast<Gameplay::EEnemyState>(i);
            }
        }

        return Gameplay::EEnemyState::Moving_Right;
    }

    void ChooseMoveDestination(Gameplay::EnemyComponent& enemy, Gameplay::VelocityComponent& velocity,
                               Animation::AnimationComponent& animation,
                               Animation::AnimationFrameComponent& animationFrame, Animation::ImageComponent& sprite,
                               const Gameplay::Transform2D& pos)
    {
        switch (PickRandomDirection(enemy, pos))
        {
            case Gameplay::EEnemyState::Moving_Left:
            {
                enemy.m_Destination.x = pos.m_Pos.x + -1.0f * GetRandomValue(s_MinMoveDistance, s_MaxMoveDistance);
                enemy.m_Destination.y = pos.m_Pos.y;
                velocity.m_Direction = {-1, 0};
                enemy.m_State = Gameplay::EEnemyState::Moving_Left;
                Animation::UpdateAnimation(animationFrame, sprite, animation, AssetManager::s_EnemyAsset,
                                           Animation::MOVE_LEFT);
                break;
            }
            case Gameplay::EEnemyState::Moving_Right:
            {
                enemy.m_Destination.x = pos.m_Pos.x + GetRandomValue(s_MinMoveDistance, s_MaxMoveDistance);
                enemy.m_Destination.y = pos.m_Pos.y;
                velocity.m_Direction = {1, 0};
                enemy.m_State = Gameplay::EEnemyState::Moving_Right;
                Animation::UpdateAnimation(animationFrame, sprite, animation, AssetManager::s_EnemyAsset,
                                           Animation::MOVE_RIGHT);
                break;
            }
            case Gameplay::EEnemyState::Moving_Down:
            {
                enemy.m_Destination.x = pos.m_Pos.x;
                enemy.m_Destination.y = pos.m_Pos.y + GetRandomValue(s_MinMoveDistance, s_MaxMoveDistance);
                velocity.m_Direction = {0, 1};
                enemy.m_State = Gameplay::EEnemyState::Moving_Down;
                Animation::UpdateAnimation(animationFrame, sprite, animation, AssetManager::s_EnemyAsset,
                                           Animation::MOVE_DOWN);
                break;
            }
            case Gameplay::EEnemyState::Moving_Up:
            {
                enemy.m_Destination.x = pos.m_Pos.x;
                enemy.m_Destination.y = pos.m_Pos.y + -1.0f * GetRandomValue(s_MinMoveDistance, s_MaxMoveDistance);
                velocity.m_Direction = {0, -1};
                enemy.m_State = Gameplay::EEnemyState::Moving_Up;
                Animation::UpdateAnimation(animationFrame, sprite, animation, AssetManager::s_EnemyAsset,
                                           Animation::MOVE_UP);
                break;
            }
            default:
            {
                spdlog::error("Unknown direction");
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
                  .all<Animation::AnimationFrameComponent&>()
                  .all<Animation::ImageComponent&>()
                  .all<const Gameplay::Transform2D>();
}

void EnemySystem::Update(float dt)
{
    m_Query.each(
        [&](gaia::ecs::Entity entity1, Gameplay::EnemyComponent& enemy, Gameplay::VelocityComponent& velocity,
            Animation::AnimationComponent& animation, Animation::AnimationFrameComponent& animationFrame,
            Animation::ImageComponent& sprite, const Gameplay::Transform2D& pos)
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
                        ChooseMoveDestination(enemy, velocity, animation, animationFrame, sprite, pos);
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
                    spdlog::error("Unhandled Enemy State");
            }
        });
}
