#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "snake.h"
#include "play.h"

static int DISPLAY_WIDTH = 640;
static int DISPLAY_HEIGHT = 360;
static int DISPLAY_SCALE = 2;
int frameCount = 0;
Apple* apple = new Apple;
Snake snake;

// The entry point for a PlayBuffer program
void MainGameEntry(PLAY_IGNORE_COMMAND_LINE)
{
	Play::CreateManager(DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE);
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate(float elapsedTime)
{
	Play::PresentDrawingBuffer();
	Play::ClearDrawingBuffer(Play::cBlack);
	apple->Draw();
	snake.Update(elapsedTime);
	if (snake.Collide(apple))
	{
		delete apple;
		apple = new Apple;
		snake.AddPart();
	}
	return Play::KeyDown(VK_ESCAPE);
}

// Gets called once when the player quits the game 
int MainGameExit(void)
{
	delete apple;
	Play::DestroyManager();
	return PLAY_OK;
}