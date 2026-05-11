#include <gaia.h>
#include "raylib.h"
// using namespace gaia;

// struct Position { float x, y, z; };
// struct Velocity { float x, y, z; };
// struct Health   { float value;   };

const int screenWidth = 800;
const int screenHeight = 450;

int main() 
{

    InitWindow(screenWidth, screenHeight,"Quest");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Quest", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

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