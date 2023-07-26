#include "raylib.h"
#include "stdio.h"
#define BALL_SPEED_X 300;
#define BALL_SPEED_Y 300;

typedef struct {
  float x, y;
  float speed_x, speed_y;
  float radius;
} Ball;

void draw_ball(Ball ball) { DrawCircle(ball.x, ball.y, ball.radius, BLACK); }

typedef struct {
  float height, width;
  float x, y;
  float speed;
} Paddle;

Rectangle get_rect(Paddle paddle) {
  return (Rectangle){paddle.x, paddle.y, paddle.width, paddle.height};
}

void draw_paddle(Paddle paddle) { DrawRectangleRec(get_rect(paddle), BLACK); }

int main() {
  InitWindow(800, 600, "Pong");
  SetWindowState(FLAG_VSYNC_HINT);

  Ball ball;
  Paddle left_paddle;
  Paddle right_paddle;

  ball.x = GetScreenWidth() / 2.0f;
  ball.y = GetScreenHeight() / 2.0f;
  ball.radius = 5.0f;
  ball.speed_x = BALL_SPEED_X;
  ball.speed_y = BALL_SPEED_Y;

  left_paddle.height = 100.0f;
  left_paddle.width = 10.0f;
  left_paddle.x = 50.0f;
  left_paddle.y = GetScreenHeight() / 2.0f - left_paddle.height / 2.0f;
  left_paddle.speed = 300;

  right_paddle.height = 100.0f;
  right_paddle.width = 10.0f;
  right_paddle.x = GetScreenWidth() - 50.0f - right_paddle.width;
  right_paddle.y = GetScreenHeight() / 2.0f - left_paddle.height / 2.0f;
  right_paddle.speed = 300;

  const char *winner_text = NULL;

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
      winner_text = "Left Player Wins!";
    }

    if (ball.x < 0) {
      winner_text = "Right Player Wins!";
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

    if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.radius,
                                get_rect(left_paddle))) {
      if (ball.speed_x < 0) {
        ball.speed_x *= -1.01f;
        ball.speed_y =
            (ball.y - left_paddle.y) / (left_paddle.height / 2) * -ball.speed_x;
      }
    }

    if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.radius,
                                get_rect(right_paddle))) {

      if (ball.speed_x > 0) {
        ball.speed_x *= -1.01f;
        ball.speed_y = (ball.y - right_paddle.y) / (right_paddle.height / 2) *
                       -ball.speed_x;
      }
    }

    if (winner_text && IsKeyDown(KEY_SPACE)) {
      ball.x = GetScreenWidth() / 2.0f;
      ball.y = GetScreenHeight() / 2.0f;
      ball.speed_x = BALL_SPEED_X;
      ball.speed_y = BALL_SPEED_Y;
      winner_text = NULL;
    }

    BeginDrawing();
    ClearBackground(WHITE);
    draw_ball(ball);
    draw_paddle(left_paddle);
    draw_paddle(right_paddle);

    if (winner_text) {
      int text_width = MeasureText(winner_text, 60);
      DrawText(winner_text, (GetScreenWidth() / 2) - text_width / 2,
               GetScreenHeight() / 2 - 30, 60, GREEN);
    }

    DrawFPS(GetScreenWidth() - 100, 10);
    EndDrawing();
  }
  return 0;
}
