#include "Game.h"

#include <iostream>

#include "States/MenuState.h";

#include "Helper.h"
#include <chrono>
#include <thread>

#include "Locator.h"

int Game::Screen_Width = 0;
int Game::Screen_Height = 0;
int Game::World_Width = 0;
int Game::World_Height = 0;
int Game::FPS = 0;

Game::Game(int screenWidth, int screenHeight, int worldWidth, int worldHeight)
{
	stateMachine = nullptr;
	m_graphics = nullptr;
	Screen_Width = screenWidth;
	Screen_Height = screenHeight;
	World_Width = worldWidth;
	World_Height = worldHeight;

	FPS = 60;
}

void Game::Run()
{
	Init();

	std::chrono::system_clock::time_point timer = std::chrono::system_clock::now();

	float time = 0.0f;

	while (m_graphics->UpdateWindowMessages())
	{
		Update();		
		Render();

		std::chrono::duration<double, std::milli> work_time = std::chrono::system_clock::now() - timer;

		long time_left = (1000 / FPS) - static_cast<long>(work_time.count());

		if (time_left > 0)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(time_left));
		}

		std::chrono::duration<double, std::milli> deltaTime = std::chrono::system_clock::now() - timer;

		float m_deltaTime = static_cast<float>(deltaTime.count()) / 1000.0f;

		timer = std::chrono::system_clock::now();
		time += m_deltaTime;

		Locator::SetDeltaTime(m_deltaTime);
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

	if (!SnakeInput::Init(m_graphics))
	{
		std::cerr << "Failed to initialize input! \n";

		return false;
	}

	Locator::Initialize();

	stateMachine = new StateMachine();

	stateMachine->Init(new MenuState());

	Locator::ProvideGraphics(m_graphics);
	Locator::ProvideStateMachine(stateMachine);

	return true;
}

void Game::Update()
{
	stateMachine->Update();
}

void Game::Render()
{
	stateMachine->Render();

	m_graphics->Render();
}

void Game::CleanUp()
{
	Locator::Terminate();
	stateMachine->CleanUp();
	SnakeInput::CleanUp();

	delete stateMachine;
	stateMachine = nullptr;

	delete m_graphics;
	m_graphics = nullptr;
}
