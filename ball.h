#ifndef BALL_H
#define BALL_H

#include "raylib.h"

typedef struct Ball
{
    Vector2 position;
    int radius;
    Color color;
    Vector2 velocity;
}Ball;


Ball CreateBall(int x, int y);

Ball UpdateBall(float dt, Ball ball);

Ball CheckWallCollision(Ball ball);

#endif