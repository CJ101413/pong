#define BALL_RADIUS 10.00f
#define VELOCITY_X -500
#define VELOCITY_Y 50
#define SCREEN_HEIGHT 720
#define SCREEN_WIDTH 1280

#include "ball.h"

Ball CreateBall(int x, int y)
{
    Ball ball =
    {
        .position = {x, y},
        .color = WHITE,
        .radius = BALL_RADIUS,
        .velocity = {VELOCITY_X, VELOCITY_Y}
    };

    return ball;
}

Ball UpdateBall(float dt, Ball ball)
{
    ball.position.x -= ball.velocity.x * dt;
    ball.position.y -= ball.velocity.y * dt;

    if(ball.position.x < 0)
    {
        ball.position.x = 640;
        ball.position.y = 360;
    }

    return ball;
}

Ball CheckWallCollision(Ball ball)
{
    if(ball.position.x >= SCREEN_WIDTH)
        ball.velocity.x *= -1;
    if(ball.position.y < 0)
        ball.velocity.y *= -1;
    if(ball.position.y > SCREEN_HEIGHT)
        ball.velocity.y *= -1;

    return ball;
}