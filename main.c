#include "raylib.h"

int main(void) {
  InitWindow(800, 600, "Pong");
  SetWindowState(FLAG_VSYNC_HINT);

  float ball_x = GetScreenWidth() / 2.0f;
  float ball_y = GetScreenHeight() / 2.0f;
  float ball_radius = 5.0f;

  float rectangle_height = 100.0f;
  float rectangle_width = 10.0f;
  float rectangle_left_x = 50.0f;
  float rectangle_left_y = GetScreenHeight() / 2.0f - rectangle_height / 2.0f;
  float rectangle_right_y = GetScreenHeight() / 2.0f - rectangle_height / 2.0f;
  float rectangle_right_x = GetScreenWidth() - 50.0f - rectangle_width;

  while (!WindowShouldClose()) {
    ball_x += 1 * GetFrameTime();
    ball_y += 1 * GetFrameTime();
    float frame_time = GetFrameTime();

    BeginDrawing();
    ClearBackground(WHITE);
    DrawText("frametime: ", 10, 40, 20, BLACK);
    DrawText(TextFormat("%f ms", frame_time * 1000), 120, 40, 20, BLACK);
    DrawCircle(ball_x, ball_y, ball_radius, BLACK);
    DrawRectangle(rectangle_left_x, rectangle_left_y, rectangle_width,
                  rectangle_height, BLACK);
    DrawRectangle(rectangle_right_x, rectangle_right_y, rectangle_width,
                  rectangle_height, BLACK);
    DrawFPS(10, 10);
    EndDrawing();
  }
  return 0;
}
