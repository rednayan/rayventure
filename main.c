#include "raylib.h"

struct Ball {
  float x, y;
  float speed_x, speed_y;
  float radius;
};

void draw_ball(struct Ball ball) {
  DrawCircle(ball.x, ball.y, ball.radius, BLACK);
}

struct Paddle {
  float height;
  float width;
  float x;
  float y;
};

void draw_paddle(struct Paddle paddle) {
  DrawRectangle(paddle.x, paddle.y, paddle.width, paddle.height, BLACK);
}

int main() {
  InitWindow(800, 600, "Pong");
  SetWindowState(FLAG_VSYNC_HINT);

  struct Ball ball;
  struct Paddle paddle1;
  struct Paddle paddle2;

  ball.x = GetScreenWidth() / 2.0f;
  ball.y = GetScreenHeight() / 2.0f;
  ball.radius = 5.0f;
  ball.speed_x = 100;
  ball.speed_y = 300;

  paddle1.height = 100.0f;
  paddle1.width = 10.0f;
  paddle1.x = 50.0f;
  paddle1.y = GetScreenHeight() / 2.0f - paddle1.height / 2.0f;

  paddle2.height = 100.0f;
  paddle2.width = 10.0f;
  paddle2.x = GetScreenWidth() - 50.0f - paddle2.width;
  paddle2.y = GetScreenHeight() / 2.0f - paddle1.height / 2.0f;

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
    draw_ball(ball);
    draw_paddle(paddle1);
    draw_paddle(paddle2);
    DrawText(TextFormat("%f ms", frame_time * 1000), GetScreenWidth() - 140, 40,
             20, BLACK);
    DrawFPS(GetScreenWidth() - 100, 10);
    EndDrawing();
  }
  return 0;
}
