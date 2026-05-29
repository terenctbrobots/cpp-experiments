#include <gaia.h>
#include <cmath>
#include "raylib.h"

#include "Animation.h"
#include "Game.h"
#include "Hash.h"
#include "Player.h"
#include "Components/VelocityComponent.h"

const int screenWidth = 1280;
const int screenHeight = 960;

const int virtualWidth = 320;
const int virtualHeight = 240;

int main() 
{
    gaia::ecs::World world;
    Game game(world);
    float dt = 0.0f;


    InitWindow(screenWidth, screenHeight,"Quest");
    SetTargetFPS(60);

    gaia::ecs::Entity player = Player::Create(world);

    if (player == gaia::ecs::EntityBad)
    {
        CloseWindow();
        return 0;
    }

    game.RegisterSystems(dt);

    RenderTexture2D target = LoadRenderTexture(virtualWidth, virtualHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);

    while (!WindowShouldClose())
    {
        dt = GetFrameTime();

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

        if (IsKeyReleased(KEY_RIGHT) || 
            IsKeyReleased(KEY_LEFT) ||
            IsKeyReleased(KEY_DOWN) ||
            IsKeyReleased(KEY_UP) ||
            IsKeyReleased(KEY_SPACE))
            {
                Player::Idle(world, player);
            }

    
        BeginTextureMode(target);
    
        world.update();

        EndTextureMode();

        float scale = fminf((float)GetScreenWidth()/virtualWidth, (float)GetScreenHeight()/virtualHeight);
    
        BeginDrawing();
        Rectangle sourceRect = { 0.0f, 0.0f, (float)target.texture.width, -(float)target.texture.height};
        Rectangle destRect = {
            (GetScreenWidth() - ((float) virtualWidth * scale)) * 0.5f,
            (GetScreenHeight() - ((float) virtualHeight * scale)) * 0.5f,
            (float)virtualWidth * scale,
            (float)virtualHeight * scale
        };

        DrawTexturePro(target.texture, sourceRect, destRect, {0,0}, 0.0f, WHITE);
        EndDrawing();
    }

    game.Cleanup();

    CloseWindow();
    return 0;
}