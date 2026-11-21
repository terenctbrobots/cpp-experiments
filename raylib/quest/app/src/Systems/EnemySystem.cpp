#include "Systems/EnemySystem.h"

#include "Components/EnemyComponent.h"
#include "Components/Transform2D.h"
#include "Components/VelocityComponent.h"
#include "raylib.h"
#include "raymath.h"

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
        });
}
