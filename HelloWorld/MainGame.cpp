#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "snake.h"



// The entry point for a PlayBuffer program
void MainGameEntry(PLAY_IGNORE_COMMAND_LINE)
{
	Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
	Test();
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate(float elapsedTime)
{

	StepFrame();
	/*int a = Play::RandomRollRange(0, 100);
	int b = Play::RandomRollRange(0, 100);
	int c = Play::RandomRollRange(0, 100);
	Play::DrawCircle({ 640 / 2, 360 / 2 }, 3, Play::Colour(a, b, c));
	Play::DrawCircle({ 640 / 2+7, 360 / 2}, 3, Play::Colour(a,b,c));*/
	
	//Play::DrawDebugText({ DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, "Hello World!");
	Play::PresentDrawingBuffer();
	return Play::KeyDown(VK_ESCAPE);
}

// Gets called once when the player quits the game 
int MainGameExit(void)
{
	Play::DestroyManager();
	return PLAY_OK;
}