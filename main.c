#include "raylib.h"

struct Ball {
  float x, y;
  float speed_x, speed_y;
  float radius;
};

int main() {
  InitWindow(800, 600, "Pong");
  SetWindowState(FLAG_VSYNC_HINT);

  struct Ball ball;

  ball.x = GetScreenWidth() / 2.0f;
  ball.y = GetScreenHeight() / 2.0f;
  ball.radius = 5.0f;
  ball.speed_x = 100;
  ball.speed_y = 300;

  float rectangle_height = 100.0f;
  float rectangle_width = 10.0f;
  float rectangle_left_x = 50.0f;
  float rectangle_left_y = GetScreenHeight() / 2.0f - rectangle_height / 2.0f;
  float rectangle_right_y = GetScreenHeight() / 2.0f - rectangle_height / 2.0f;
  float rectangle_right_x = GetScreenWidth() - 50.0f - rectangle_width;

  while (!WindowShouldClose()) {
    float frame_time = GetFrameTime();

    ball.x += ball.speed_x * frame_time;
    ball.y += ball.speed_y * frame_time;

    if (ball.y < 0) {
      ball.y = 0;
      ball.speed_y *= -1;
    }

    if (ball.y > GetScreenHeight()) {
      ball.y = GetScreenHeight();
      ball.speed_y *= -1;
    }

    BeginDrawing();
    ClearBackground(WHITE);
    DrawCircle(ball.x, ball.y, ball.radius, BLACK);
    DrawRectangle(rectangle_left_x, rectangle_left_y, rectangle_width,
                  rectangle_height, BLACK);
    DrawRectangle(rectangle_right_x, rectangle_right_y, rectangle_width,
                  rectangle_height, BLACK);
    DrawText(TextFormat("%f ms", frame_time * 1000), GetScreenWidth() - 140, 40,
             20, BLACK);
    DrawFPS(GetScreenWidth() - 100, 10);
    EndDrawing();
  }
  return 0;
}
