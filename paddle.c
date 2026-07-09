#define PADDLE_WIDTH 10
#define PADDLE_HEIGHT 80
#define PADDLE_SPEED 500.00f
#define SCREEN_HEIGHT 720

#include "paddle.h"
#include "ball.h"

Paddle CreatePaddle(int x, int y)
{
    Paddle player =
    {
        .position = {x, y},
        .width = PADDLE_WIDTH,
        .height = PADDLE_HEIGHT,
        .color = WHITE,
        .speed = PADDLE_SPEED
    };

    return player;
}

Paddle UpdatePaddle(float dt, Paddle player)
{
    if(IsKeyDown(KEY_W))
        player.position.y -= player.speed * dt;
    else if(IsKeyDown(KEY_S))
        player.position.y += player.speed * dt;

    if(player.position.y <= 0)
        player.position.y = 0;
    else if(player.position.y >= SCREEN_HEIGHT - PADDLE_HEIGHT)
        player.position.y = SCREEN_HEIGHT - PADDLE_HEIGHT;

    return player;
}

Ball CheckPlayerCollision(Ball ball, Paddle player, Rectangle playerRec)
{
    if(CheckCollisionCircleRec(ball.position, ball.radius, playerRec))
    {
         if (CheckCollisionCircleRec(ball.position, ball.radius, playerRec))
        {
            ball.velocity.x *= -1;

            float paddleCenter = player.position.y + player.height / 2.0f;
            float hitOffset = (ball.position.y - paddleCenter) / (player.height / 2.0f);

            ball.velocity.y = hitOffset * 400.0f;
        }

    }

    return ball;
}