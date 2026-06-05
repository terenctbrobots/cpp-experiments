#include "Animation.h"
#include "Components/VelocityComponent.h"
#include "Game.h"
#include "Hash.h"
#include "Player.h"
#include "raylib.h"

#include <cmath>
#include <gaia.h>

const int screenWidth = 1280;
const int screenHeight = 960;

int main()
{
    gaia::ecs::World world;
    Game game(world);
    float dt = 0.0f;

    InitWindow(screenWidth, screenHeight, "Quest");
    SetTargetFPS(60);

    gaia::ecs::Entity player = Player::Create(world);

    if (player == gaia::ecs::EntityBad)
    {
        CloseWindow();
        return 0;
    }

    game.SetupTileMap();

    game.RegisterSystems(dt);

    bool shouldExit = false;

    Camera2D camera = {0};
    camera.offset = (Vector2){(float)screenWidth / 2.0f, (float)screenHeight / 2.0f}; // Pivot
    camera.rotation = 0.0f;
    camera.zoom = 4.0f;

    Player::SetPosition(world, player, camera.offset);
    while (!WindowShouldClose() && !shouldExit)
    {
        dt = GetFrameTime();

        if (IsKeyPressed(KEY_ESCAPE))
        {
            shouldExit = true;
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            Player::Movement(world, player, {1.0f, 0.0f}, Animation::MOVE_RIGHT);
        }
        if (IsKeyDown(KEY_LEFT))
        {
            Player::Movement(world, player, {-1.0f, 0.0f}, Animation::MOVE_LEFT);
        }

        if (IsKeyDown(KEY_DOWN))
        {
            Player::Movement(world, player, {0.0f, 1.0f}, Animation::MOVE_DOWN);
        }

        if (IsKeyDown(KEY_UP))
        {
            Player::Movement(world, player, {0.0f, -1.0f}, Animation::MOVE_UP);
        }

        if (IsKeyDown(KEY_SPACE))
        {
            Player::Attack(world, player);
        }

        if (IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_LEFT) || IsKeyReleased(KEY_DOWN) || IsKeyReleased(KEY_UP) ||
            IsKeyReleased(KEY_SPACE))
        {
            Player::Idle(world, player);
        }

        game.Update(dt);
        camera.target = Player::GetPosition(world, player);

        BeginDrawing();
        BeginMode2D(camera);
        game.Render();
        EndMode2D();
        EndDrawing();
    }

    game.Cleanup();

    CloseWindow();
    return 0;
}