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
    return false;
}

void GameState::Update()
{
	if (isPaused) return;


}

void GameState::Render()
{
	RenderBorder();
}

void GameState::CleanUp()
{
	stateMachine->CleanUp();
	delete stateMachine;
}

void GameState::KeyDown(int Key)
{
	switch (Key)
	{
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
		Locator::GetGraphics()->PlotTile(x, 0, 0, RED, RED, ' ');

		Locator::GetGraphics()->PlotTile(x, Locator::GetGraphics()->GetNumRows() - 1, 0, RED, RED, ' ');
	}

	for (int y = 0; y < Locator::GetGraphics()->GetNumRows(); y++)
	{
		Locator::GetGraphics()->PlotTile(0, y, 0, RED, RED, ' ');

		Locator::GetGraphics()->PlotTile(Locator::GetGraphics()->GetNumColumns() - 1, y, 0, RED, RED, ' ');
	}
}
