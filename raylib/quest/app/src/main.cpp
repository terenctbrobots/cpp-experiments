#include <gaia.h>
#include <cmath>
#include "raylib.h"
#include "Game.h"
#include "Player.h"
#include "Components/PlayerComponent.h"

const int screenWidth = 640;
const int screenHeight = 480;

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

        if (IsKeyDown(KEY_RIGHT)) world.set<PlayerComponent>(player) = {1.0, 0};
        if (IsKeyDown(KEY_LEFT)) world.set<PlayerComponent>(player) = {-1.0, 0};
        if (IsKeyDown(KEY_DOWN)) world.set<PlayerComponent>(player) = {0, 1.0};
        if (IsKeyDown(KEY_UP)) world.set<PlayerComponent>(player) = {0, -1.0};

        if (IsKeyReleased(KEY_RIGHT) || 
            IsKeyReleased(KEY_LEFT) ||
            IsKeyReleased(KEY_DOWN) ||
            IsKeyReleased(KEY_UP))
            {
                world.set<PlayerComponent>(player) = {0, 0};
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