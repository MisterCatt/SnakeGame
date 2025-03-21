#pragma once
#include "SnakeLibrary/SnakeGraphics.h"
#include "SnakeLibrary/SnakeInput.h"

class Game
{
private:
	int FPS = 60;

	int Screen_Width;
	int Screen_Height;

	int World_Width;
	int World_Height;

	SnakeGraphics* m_graphics;
public:
	Game(int screenWidth = 1024, int screenHeight = 768,int worldWidth = 60, int worldHeight = 30);

	void Run();
private:
	bool Init();
	void Update();
	void Render();
	void CleanUp();
};

