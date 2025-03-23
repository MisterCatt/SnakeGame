#include "GameState.h"
#include "../GraphicsLocator.h"
#include "../Helper.h"
#include <iostream>
#include "../SnakeLibrary/SnakeInput.h"

StateMachine* GameState::stateMachine = nullptr;

bool GameState::Init()
{
	stateMachine = new StateMachine();
    return false;
}

void GameState::Update()
{
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
		DestroyWindow(GraphicsLocator::GetGraphics()->Hwnd);
		break;
	default:
		std::cout << Key << "\n";
		break;
	}
}

void GameState::RenderBorder()
{
	for (int x = 0; x < GraphicsLocator::GetGraphics()->GetNumColumns(); x++)
	{
		GraphicsLocator::GetGraphics()->PlotTile(x, 0, 0, RED, RED, ' ');

		GraphicsLocator::GetGraphics()->PlotTile(x, GraphicsLocator::GetGraphics()->GetNumRows() - 1, 0, RED, RED, ' ');
	}

	for (int y = 0; y < GraphicsLocator::GetGraphics()->GetNumRows(); y++)
	{
		GraphicsLocator::GetGraphics()->PlotTile(0, y, 0, RED, RED, ' ');

		GraphicsLocator::GetGraphics()->PlotTile(GraphicsLocator::GetGraphics()->GetNumColumns() - 1, y, 0, RED, RED, ' ');
	}
}
