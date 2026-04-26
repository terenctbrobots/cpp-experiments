#include "raylib.h"

int main() {
    // 1. Initialization
    InitWindow(800, 450, "raylib [core] example - basic window");
    SetTargetFPS(60); // Set game to run at 60 frames-per-second

    // 2. Main Game Loop
    while (!WindowShouldClose()) {
        // Update logic (input, physics, etc.)
        
        // Draw logic
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    // 3. De-initialization
    CloseWindow();
    return 0;
}
