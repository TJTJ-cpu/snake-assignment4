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

class SnakePart;

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
	//void Collide(Apple* apple);
};

class SnakePart
{
private:
	Point2D position;
	Play::Colour colour = Play::cRed;

public:
	friend class Snake;
	SnakePart();
	SnakePart(int x, int y);
	void Draw();
};

class Apple
{
private:
	Point2D position;
public:
	Apple();
	void Draw();
};