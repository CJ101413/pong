#ifndef PADDLE_H
#define PADDLE_H

#include "raylib.h"
#include "ball.h"

typedef struct Paddle
{
    Vector2 position;
    int width;
    int height;
    Color color;
    float speed;
    
}Paddle;

Paddle CreatePaddle(int x, int y);

Paddle UpdatePaddle(float dt, Paddle player);

Ball CheckPlayerCollision(Ball ball, Paddle player, Rectangle playerRec);

#endif