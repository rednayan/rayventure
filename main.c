#include "raylib.h"

int main(void) {
  InitWindow(800, 600, "Pong");
  SetWindowState(FLAG_VSYNC_HINT);

  float ball_x = GetScreenWidth() / 2.0;
  float ball_y = GetScreenHeight() / 2.0;
  float ball_radius = 5.0;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    DrawCircle(ball_x, ball_y, ball_radius, BLACK);
    DrawRectangle(50, GetScreenHeight() / 2 - 50, 10, 100, BLACK);
    DrawRectangle(GetScreenWidth() - 50 - 10, GetScreenHeight() / 2 - 50, 10,
                  100, BLACK);
    DrawFPS(10, 10);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}