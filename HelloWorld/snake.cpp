#include "snake.h"

extern Apple* apple;
extern int frameCount;

Snake::Snake()
{
    heading = Heading::West;
    numParts = 2;
    this->parts = new SnakePart[numParts];
    this->parts[0] = SnakePart(320, 180);
    this->parts[1] = SnakePart(310, 180);
}

Snake::~Snake()
{
    delete[] this->parts;
}

void Snake::Draw()
{
    for (int i = 0; i < numParts; i++)
    {
        parts[i].Draw();
    }
}

void Snake::Handle()
{
    if (Play::KeyPressed(VK_UP))
    {
        heading = Heading::North;
    }
    if (Play::KeyPressed(VK_DOWN))
    {
        heading = Heading::South;
    }
    if (Play::KeyPressed(VK_RIGHT))
    {
        heading = Heading::East;
    }
    if (Play::KeyPressed(VK_LEFT))
    {
        heading = Heading::West;
    }
}

void Snake::Move()
{
    for (int i = numParts - 1; i > 0; i--)
    {
        parts[i].position = parts[i - 1].position;
    }
    switch (heading)
    {
    case Heading::North:
        parts[0].position.y -= 10;
        break;
    case Heading::South:
        parts[0].position.y += 10;
        break;
    case Heading::East:
        parts[0].position.x += 10;
        break;
    case Heading::West:
        parts[0].position.x -= 10;
        break;
    }
}

void Snake::AddPart()
{
    SnakePart* newParts = new SnakePart[numParts + 1];
    for (int i = 0; i < numParts; i++)
    {
        newParts[i] = parts[i];
    }
    delete[] parts;
    parts = newParts;
    parts[numParts] = SnakePart(parts[numParts - 1].getPos());
    numParts++;
}

void Snake::Update(float time)
{
    if (frameCount % 6 == 0)
    {
        Move();
    }
    Handle();
    Draw();
    frameCount++;
}

bool Snake::Collide(Apple* apple)
{
    Point2D snakeHead = parts[0].getPos();
    Point2D applePos = apple->getPos();
    float distance = sqrt(pow(snakeHead.x - applePos.x, 2) + pow(snakeHead.y - applePos.y, 2));
    if (distance <= CloseProximityDistance)
    {
        return true;
    }
    return false;
}


