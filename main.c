#include "raylib.h"

int main(void) {
  InitWindow(800, 600, "Pong");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    DrawFPS(10, 10);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}