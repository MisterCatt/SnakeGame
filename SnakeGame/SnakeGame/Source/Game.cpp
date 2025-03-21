#include "Game.h"

#include <iostream>

#include "GraphicsLocator.h"
#include "Helper.h"

Game::Game(int screenWidth, int screenHeight, int worldWidth, int worldHeight)
{
	m_graphics = nullptr;
	Screen_Width = screenWidth;
	Screen_Height = screenHeight;
	World_Width = worldWidth;
	World_Height = worldHeight;
}

void Game::Run()
{
	Init();

	while (m_graphics->UpdateWindowMessages())
	{
		Update();
		Render();
	}

	CleanUp();
}

bool Game::Init()
{
	m_graphics = new SnakeGraphics(Screen_Width, Screen_Height, World_Width, World_Height);

	if (!m_graphics->Init())
	{
		std::cerr << "Failed to initialize graphics \n";
		return false;
	}

	GraphicsLocator::provide(m_graphics);

	return true;
}

void Game::Update()
{
}

void Game::Render()
{
	m_graphics->PlotTile(10, 10, 1, RED, RED, ' ');

	m_graphics->Render();
}

void Game::CleanUp()
{
	delete m_graphics;
	m_graphics = nullptr;
}
