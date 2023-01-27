#pragma once
#include "Play.h"
#include <ctime>

enum Heading
{
	North,
	South,
	East,
	West
};

const int CloseProximityDistance = 10;

class SnakePart;
class Apple;

class Snake
{
private:
	Heading heading;
	SnakePart* parts;
	int numParts;
public:
	Snake();
	~Snake();
	void Draw();
	void Handle();
	void Move();
	void AddPart();
	void Update(float f);
	bool Collide(Apple* apple);
};

class SnakePart
{
private:
	Point2D position;
	Play::Colour colour = Play::cRed;

public:
	friend class Snake;
	Point2D getPos() { return position; }
	SnakePart();
	SnakePart(int x, int y);
	SnakePart(Point2D p);
	void Draw();
};

class Apple
{
private:
	Point2D position;
public:
	friend class Snake;
	Point2D getPos() { return position; }
	Apple();
	void Draw();
};