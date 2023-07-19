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
  float height, width;
  float x, y;
  float speed;
};

void draw_paddle(struct Paddle paddle) {
  DrawRectangle(paddle.x, paddle.y, paddle.width, paddle.height, BLACK);
}

int main() {
  InitWindow(800, 600, "Pong");
  SetWindowState(FLAG_VSYNC_HINT);

  struct Ball ball;
  struct Paddle left_paddle;
  struct Paddle right_paddle;

  ball.x = GetScreenWidth() / 2.0f;
  ball.y = GetScreenHeight() / 2.0f;
  ball.radius = 5.0f;
  ball.speed_x = 100;
  ball.speed_y = 300;

  left_paddle.height = 100.0f;
  left_paddle.width = 10.0f;
  left_paddle.x = 50.0f;
  left_paddle.y = GetScreenHeight() / 2.0f - left_paddle.height / 2.0f;
  left_paddle.speed = 100;

  right_paddle.height = 100.0f;
  right_paddle.width = 10.0f;
  right_paddle.x = GetScreenWidth() - 50.0f - right_paddle.width;
  right_paddle.y = GetScreenHeight() / 2.0f - left_paddle.height / 2.0f;
  right_paddle.speed = 100;

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

    if (ball.x > GetScreenWidth()) {
      ball.x = GetScreenWidth();
      ball.speed_x *= -1;
    }

    if (ball.x < 0) {
      ball.x = 0;
      ball.speed_x *= -1;
    }

    if (IsKeyDown(KEY_W)) {
      left_paddle.y -= left_paddle.speed * frame_time;
    }
    if (IsKeyDown(KEY_S)) {
      left_paddle.y += left_paddle.speed * frame_time;
    }
    if (IsKeyDown(KEY_K)) {
      right_paddle.y -= left_paddle.speed * frame_time;
    }
    if (IsKeyDown(KEY_J)) {
      right_paddle.y += left_paddle.speed * frame_time;
    }

    BeginDrawing();
    ClearBackground(WHITE);
    draw_ball(ball);
    draw_paddle(left_paddle);
    draw_paddle(right_paddle);
    DrawText(TextFormat("%f ms", frame_time * 1000), GetScreenWidth() - 140, 40,
             20, BLACK);
    DrawFPS(GetScreenWidth() - 100, 10);
    EndDrawing();
  }
  return 0;
}
