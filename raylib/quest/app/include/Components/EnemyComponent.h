#pragma once

#include <cstdint>
namespace Gameplay
{
    enum EnemyState : uint8_t
    {
        Idle,
        Moving_Left,
        Moving_Right,
        Moving_Down,
        Moving_Up,
        Attacking
    };

    struct EnemyComponent
    {
        EnemyState m_State = EnemyState::Idle;
    };
} // namespace Gameplay
