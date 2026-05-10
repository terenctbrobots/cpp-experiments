#include "raylib.h"

int main(int argc, char*argv[])
{
    // 1. Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Raylib - Basic Input Example");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    // 2. Main Game Loop
    while (!WindowShouldClose()) {    // Detect window close button or ESC key
        // Update
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Move the ball with arrow keys", 10, 10, 20, DARKGRAY);
            DrawCircleV(ballPosition, 40, MAROON);
        EndDrawing();
    }

    // 3. De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}