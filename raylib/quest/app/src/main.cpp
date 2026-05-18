#include <gaia.h>
#include <cmath>
#include "raylib.h"

#include "Game.h"
#include "Player.h"

#include "Components/PlayerComponent.h"
// using namespace gaia;

// struct Position { float x, y, z; };
// struct Velocity { float x, y, z; };
// struct Health   { float value;   };

const int screenWidth = 2560;
const int screenHeight = 1920;

const int virtualWidth = 320;
const int virtualHeight = 240;

int main() 
{
    gaia::ecs::World world;
    Game game(world);

    game.RegisterSystems();

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

        float dt = GetFrameTime();

        if (IsKeyDown(KEY_RIGHT)) world.set<PlayerComponent>(player) = {dt, 1.0, 0};
        if (IsKeyDown(KEY_LEFT)) world.set<PlayerComponent>(player) = {dt, -1.0, 0};
        if (IsKeyDown(KEY_DOWN)) world.set<PlayerComponent>(player) = {dt, 0, 1.0};
        if (IsKeyDown(KEY_UP)) world.set<PlayerComponent>(player) = {dt, 0, -1.0};

        if (IsKeyReleased(KEY_RIGHT) || 
            IsKeyReleased(KEY_LEFT) ||
            IsKeyReleased(KEY_DOWN) ||
            IsKeyReleased(KEY_UP))
            {
                world.set<PlayerComponent>(player) = {dt, 0,0};
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