#pragma once
#include "Play.h"
#include <iostream>
#include <string>
#include <vector>

static int DISPLAY_WIDTH = 640;
static int DISPLAY_HEIGHT = 360;
static int DISPLAY_SCALE = 2;
static unsigned int* snakePart;
static int snakePartCount;
static int fpsCounter = 0;


void Test();
void StepFrame();

class Apple
{
public:
	void DrawApple();
};

class SnakePart
{
public:
	void DrawSnakePart();

};

class Snake
{
public:
	void Draw();
	void Move();
	



};