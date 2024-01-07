#include "raylib.h"

void drawBackground() {
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    for (int x = 0; x < screenWidth; x += 10) {
        for (int y = 0; y < screenHeight; y += 10) {
            DrawPixel(x, y, WHITE);
        }
    }
}

int main() {

    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Generation");

    SetTargetFPS(60);

    while (!WindowShouldClose())  
    {

        BeginDrawing();

            ClearBackground(BLACK);
            drawBackground();

        EndDrawing();

    }


    return 0;
}