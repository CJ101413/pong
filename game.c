#include "game.h"

Ball CheckPlayerCollision(Ball ball, Paddle player, Rectangle playerRec)
{
    if(CheckCollisionCircleRec(ball.position, ball.radius, playerRec) && ball.velocity.x > 0)
    {
            ball.velocity.x *= -1;
            ball.position.x = 100;

            float paddleCenter = player.position.y + player.height / 2.0f;
            float hitOffset = (ball.position.y - paddleCenter) / (player.height / 2.0f);

            ball.velocity.y = hitOffset * 400.0f;
    }

    return ball;
}