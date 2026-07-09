//Pong v2
#include "raylib.h"
#include "paddle.h"
#include "ball.h"

int main(void)
{
    InitWindow(1280, 720, "Pong");
    SetTargetFPS(60);

    Paddle player = CreatePaddle(80, 200);
    Ball ball = CreateBall(640, 360);

    while(!WindowShouldClose())
    {
        Rectangle playerRec = { player.position.x, player.position.y, player.width, player.height };

        player = UpdatePaddle(GetFrameTime(), player);
        
        ball = UpdateBall(GetFrameTime(), ball);
        ball = CheckWallCollision(ball);
        ball = CheckPlayerCollision(ball, player, playerRec);

        BeginDrawing();

            ClearBackground(BLACK);

            DrawRectangle(640, 0, 4, 1280, WHITE);
            DrawRectangle(player.position.x, player.position.y, player.width, player.height, player.color);
            DrawCircle(ball.position.x, ball.position.y, ball.radius, ball.color);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}