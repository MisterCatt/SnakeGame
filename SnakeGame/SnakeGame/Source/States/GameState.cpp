#include "GameState.h"
#include "../Helper.h"
#include "../SnakeLibrary/SnakeInput.h"
#include <iostream>

#include "../Locator.h"
#include "../SnakeLibrary/SnakeGraphics.h"

StateMachine* GameState::stateMachine = nullptr;

bool GameState::Init()
{
	stateMachine = new StateMachine();

	snake.init(Vector2Int { 20, 20 });

    return false;
}

void GameState::Update()
{
	if (isPaused) return;

	snake.Update();
}

void GameState::Render()
{
	for (int x = 0; x < Locator::GetGraphics()->GetNumColumns(); x++)
	{
		for (int y = 0; y < Locator::GetGraphics()->GetNumRows(); y++)
		{
			Locator::GetGraphics()->PlotTile(x, y, 0, BLACK, BLACK, ' ');

		}
	}

	snake.Render();

	RenderBorder();
}

void GameState::CleanUp()
{
	snake.CleanUp();

	stateMachine->CleanUp();
	delete stateMachine;
}

void GameState::KeyDown(int Key)
{
	switch (Key)
	{
	case 87:
	case 38:
		//Up
		snake.direction = SnakeTail::Direction::Up;
		break;
	case 83:
	case 40:
		//Down
		snake.direction = SnakeTail::Direction::Down;
		break;
	case 37:
	case 65:
		//Left
		snake.direction = SnakeTail::Direction::Left;
		break;
	case 39:
	case 68:
		//Right
		snake.direction = SnakeTail::Direction::Right;
		break;
	case 32:
		snake.AddTail();
		break;
	case 27:
		DestroyWindow(Locator::GetGraphics()->Hwnd);
		break;
	default:
		std::cout << Key << "\n";
		break;
	}
}

void GameState::RenderBorder()
{
	for (int x = 0; x < Locator::GetGraphics()->GetNumColumns(); x++)
	{
		Locator::GetGraphics()->PlotTile(x, 0, 1, RED, RED, ' ');

		Locator::GetGraphics()->PlotTile(x, Locator::GetGraphics()->GetNumRows() - 1, 1, RED, RED, ' ');
	}

	for (int y = 0; y < Locator::GetGraphics()->GetNumRows(); y++)
	{
		Locator::GetGraphics()->PlotTile(0, y, 1, RED, RED, ' ');

		Locator::GetGraphics()->PlotTile(Locator::GetGraphics()->GetNumColumns() - 1, y, 1, RED, RED, ' ');
	}
}
