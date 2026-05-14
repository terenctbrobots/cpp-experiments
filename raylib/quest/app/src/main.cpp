#include <gaia.h>
#include <cmath>
#include "raylib.h"

#include "Game.h"
#include "Player.h"
#include "Render.h"
// using namespace gaia;

// struct Position { float x, y, z; };
// struct Velocity { float x, y, z; };
// struct Health   { float value;   };

const int screenWidth = 1280;
const int screenHeight = 720;

const int virtualWidth = 320;
const int virtualHeight = 180;

const float speed = 200.0f;

int main() 
{
    gaia::ecs::World world;

    InitWindow(screenWidth, screenHeight,"Quest");
    SetTargetFPS(60);

    if (!Player::Create(world))
    {
        CloseWindow();
        return 0;
    }

    RenderTexture2D target = LoadRenderTexture(virtualWidth, virtualHeight);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT);

    while (!WindowShouldClose())
    {

        float dt = GetFrameTime();

        if (IsKeyDown(KEY_RIGHT)) Player::Move(world, speed, dt, 1.0, 0);
        if (IsKeyDown(KEY_LEFT))  Player::Move(world, speed, dt, -1.0, 0);
        if (IsKeyDown(KEY_DOWN))  Player::Move(world, speed, dt, 0.0, 1.0);
        if (IsKeyDown(KEY_UP))    Player::Move(world, speed, dt, 0.0, -1.0);

        float scale = fminf((float)GetScreenWidth()/virtualWidth, (float)GetScreenHeight()/virtualHeight);

        BeginTextureMode(target);
        ClearBackground(BLACK);
        Render(world);
        EndTextureMode();
        
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

    Game::Cleanup(world);

    CloseWindow();
    
 
    // ecs::World w;
    // const float dt = 0.016f;

    // auto moveSystem = w.system()
    //     .all<Position>()
    //     .all<Velocity>()
    //     .on_each([&](ecs::Iter& it) {
    //         auto p = it.view_mut<Position>();
    //         auto v = it.view<Velocity>();
    //         GAIA_EACH(it) {
    //             p[i].x += v[i].x * dt;
    //             p[i].y += v[i].y * dt;
    //             p[i].z += v[i].z * dt;
    //         }
    //     });

    // auto healthSystem = w.system()
    //     .all<Health>()
    //     .on_each([](ecs::Iter& it) {
    //         auto h = it.view_mut<Health>();
    //         GAIA_EACH(it) {
    //             h[i].value -= 1.0f;
    //         }
    //     });

    // for (int i = 0; i < 5; i++) {
    //     ecs::Entity e = w.add();
    //     w.add<Position>(e, {0.f, 0.f, 0.f});
    //     w.add<Velocity>(e, {1.f, 0.5f, 0.f});
    //     w.add<Health>(e, {100.f});
    // }

    // while (true) {
    //     w.update(); // runs all builder systems + GC
    // }

    return 0;
}