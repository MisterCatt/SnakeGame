#include "GameState.h"
#include "../Helper.h"
#include "../SnakeLibrary/SnakeInput.h"
#include <iostream>

#include "../Locator.h"
#include "../SnakeLibrary/SnakeGraphics.h"
#include "MenuState.h"

bool GameState::Init()
{
	/*stateMachine = new StateMachine();

	snake.Init(Vector2Int{ 20, 20 });
	

	apple.Init(Vector2Int{ (rand() % (Locator::GetGraphics()->GetNumColumns() - 1)) + 1,(rand() % (Locator::GetGraphics()->GetNumRows() - 1)) + 1 });*/

	world.Init();

	snake.Init({2,3});

	snake.AddObserver(this);

    return true;
}

void GameState::Update()
{
	if (isPaused) return;

	time += Locator::GetDeltaTime();
	if (time < 0.1f) return;
	time = 0.0f;

	if (snake.isAlive) {
		snake.Update();
		/*if (apple.GetPosition() == snake.GetPosition())
		{
			apple.ChangePosition(Vector2Int{ (rand() % (Locator::GetGraphics()->GetNumColumns() - 1))+1,(rand() % (Locator::GetGraphics()->GetNumRows() - 1))+1 });
			snake.AddTail();
		}*/
	}

	if (playerIsDead)
	{
		ChangeToMenu();
	}
}

void GameState::Render()
{
	world.Render();

	for (int x = 0; x < Locator::GetGraphics()->GetNumColumns(); x++)
	{
		for (int y = 0; y < Locator::GetGraphics()->GetNumRows(); y++)
		{
			Locator::GetGraphics()->PlotTile(x, y, 0, BLACK, BLACK, ' ');

		}
	}
	RenderBorder();
}

void GameState::CleanUp()
{
	snake.CleanUp();

	for (int x = 0; x < Locator::GetGraphics()->GetNumColumns(); x++)
	{
		for (int y = 0; y < Locator::GetGraphics()->GetNumRows(); y++)
		{
			Locator::GetGraphics()->PlotTile(x, y, 0, BLACK, BLACK, ' ');

			Locator::GetGraphics()->PlotTile(x, y, 1, BLACK, BLACK, ' ');
		}
	}
}

void GameState::KeyDown(int Key)
{
	switch (Key)
	{
	case 87:
	case 38:
		//Up
		snake.SetDirection(Direction::Up);
		break;
	case 83:
	case 40:
		//Down
		snake.SetDirection(Direction::Down);
		break;
	case 37:
	case 65:
		//Left
		snake.SetDirection(Direction::Left);
		break;
	case 39:
	case 68:
		//Right
		snake.SetDirection(Direction::Right);
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

void GameState::ChangeToMenu()
{
	Locator::GetStateMachine()->ChangeState(new MenuState());
}

void GameState::OnDeath()
{
	snake.RemoveObserver(this);
	playerIsDead = true;
}

void GameState::OnAppleCollision()
{

}
