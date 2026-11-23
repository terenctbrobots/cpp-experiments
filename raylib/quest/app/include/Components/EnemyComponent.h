#pragma once

#include "raylib.h"

namespace Gameplay
{
    enum EEnemyState : int
    {
        Start_Up,
        Idle,
        Moving_Left,
        Moving_Right,
        Moving_Down,
        Moving_Up,
        Attacking
    };

    struct EnemyComponent
    {
        EEnemyState m_State = EEnemyState::Start_Up;
        Vector2 m_SpawnPosition = {0, 0};
        Vector2 m_Destination = {0, 0};
    };
} // namespace Gameplay
