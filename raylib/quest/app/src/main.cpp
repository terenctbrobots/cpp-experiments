#include <gaia.h>
#include <cmath>
#include "raylib.h"
#include "Game.h"
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

    game.RegisterSystems(dt);

    InitWindow(screenWidth, screenHeight,"Quest");
    SetTargetFPS(60);

    gaia::ecs::Entity player = Player::Create(world);

    if (player == gaia::ecs::EntityBad)
    {
        CloseWindow();
        return 0;
    }

    RenderTexture2D target = LoadRenderTexture(virtualWidth, virtualHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);

    while (!WindowShouldClose())
    {
        dt = GetFrameTime();

        if (IsKeyDown(KEY_RIGHT))
        {
            auto& velocity = world.set<VelocityComponent>(player);
            velocity.m_Direction.x = 1.0f;
            velocity.m_Direction.y = 0.0f;
        }
        if (IsKeyDown(KEY_LEFT))
        {
            auto& velocity = world.set<VelocityComponent>(player);
            velocity.m_Direction.x = -1.0f;
            velocity.m_Direction.y = 0.0f;
        }
        if (IsKeyDown(KEY_DOWN))
        {
           auto& velocity = world.set<VelocityComponent>(player);
           velocity.m_Direction.x = 0.0f;
           velocity.m_Direction.y = 1.0f;
        }
        
        if (IsKeyDown(KEY_UP))
        {
           auto& velocity = world.set<VelocityComponent>(player);
           velocity.m_Direction.x = 0.0f;
           velocity.m_Direction.y = -1.0f;
        }

        if (IsKeyReleased(KEY_RIGHT) || 
            IsKeyReleased(KEY_LEFT) ||
            IsKeyReleased(KEY_DOWN) ||
            IsKeyReleased(KEY_UP))
            {
                auto& velocity = world.set<VelocityComponent>(player);
                velocity.m_Direction.x = 0.0f;
                velocity.m_Direction.y = 0.0f;
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