#include "snake.h"

Apple::Apple()
{
    srand(time(nullptr));
    position.x = rand() % 640;
    position.y = rand() % 320;
}

SnakePart::SnakePart(Point2D p)
{
    position = p;

    const Play::Colour colors[] = { Play::cRed, Play::cGreen, Play::cBlue,
        Play::cMagenta, Play::cCyan, Play::cYellow, Play::cOrange };
    colour = colors[rand() % 7];
}

SnakePart::SnakePart(int x, int y) : position(x, y)
{
    //srand(time(nullptr));
    const Play::Colour colors[] = { Play::cRed, Play::cGreen, Play::cBlue,
        Play::cMagenta, Play::cCyan, Play::cYellow, Play::cOrange };
    colour = colors[rand() % 7];
}

SnakePart::SnakePart()
{
    position.x = 0;
    position.y = 0;
    colour = Play::cRed;
}

void SnakePart::Draw()
{
    Play::DrawCircle(position, 6, colour);
}



void Apple::Draw()
{
    Play::DrawCircle(position, 6, Play::cRed);
}