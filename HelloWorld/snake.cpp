#include "snake.h"

//DISPLAY_WIDTH = 640;	640/2 = 320
//DISPLAY_HEIGHT = 360;	360/2 = 180
Apple* apple = new Apple{};
SnakePart* snakepart = new SnakePart{};

void Test()
{
	snakepart->DrawSnakePart();
	apple->DrawApple();

	delete apple;
	delete snakepart;
}

void StepFrame()
{

}

void Apple::DrawApple()
{
	int a = Play::RandomRollRange(0, 620);
	int b = Play::RandomRollRange(0, 340);
	Play::DrawCircle({ a,b }, 4, Play::cRed);
}


void SnakePart::DrawSnakePart()
{
	delete[] snakePart;
	int d = 0;
	for (int i = 0; i <= 1; i++)
	{
		int j = DISPLAY_WIDTH/2 + d;
		int k = DISPLAY_HEIGHT/2;
		int a = Play::RandomRollRange(0, 100);
		int b = Play::RandomRollRange(0, 100);
		int c = Play::RandomRollRange(0, 100);
		Play::DrawCircle({j, k}, 4, Play::Colour(a, b, c));
		d += 9;
	}


}

void Snake::Draw()
{

}

void Snake::Move()
{
	if (fpsCounter == 6)
	{


		fpsCounter = 0;
	}




	fpsCounter += 1;
}


