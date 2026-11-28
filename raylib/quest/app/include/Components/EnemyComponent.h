#pragma once

#include "raylib.h"

namespace Gameplay
{
    enum EEnemyState : int
    {
        Moving_Up, // Movement at top because can then just pick a random direction easier
        Moving_Down,
        Moving_Left,
        Moving_Right,
        Start_Up,
        Idle,
        Attacking
    };

    struct EnemyComponent
    {
        EEnemyState m_State = EEnemyState::Start_Up;
        Vector2 m_SpawnPosition = {0, 0};
        Vector2 m_Destination = {0, 0};
    };
} // namespace Gameplay
