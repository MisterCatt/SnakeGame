#pragma once
#include "SnakeLibrary/SnakeGraphics.h"
#include "SnakeLibrary/SnakeInput.h"
#include "StateMachine.h"

class Game
{
public:
	static int FPS;

	static int Screen_Width;
	static int Screen_Height;

	static int World_Width;
	static int World_Height;
	static StateMachine* stateMachine;
private:
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

