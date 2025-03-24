#include "MenuState.h"
#include "../Game.h"
#include "../Helper.h"
#include "../SnakeLibrary/SnakeInput.h"
#include <iostream>
#include "GameState.h"
#include "../Locator.h"

MenuState::~MenuState()
{
}

bool MenuState::Init()
{
	return true;
}

void MenuState::Update()
{

}

void MenuState::Render()
{
	Locator::GetGraphics()->PlotText(Game::World_Width/2-4, Game::World_Height / 2-4, 0,		BLACK, L"Snek",		WHITE, SnakeGraphics::Left);


	Locator::GetGraphics()->PlotText(Game::World_Width / 2 - 4, Game::World_Height / 2, 0,		BLACK, L"Play",		WHITE, SnakeGraphics::Left);
	Locator::GetGraphics()->PlotText(Game::World_Width / 2 - 5, Game::World_Height / 2 +1, 0,	BLACK, L"About",	WHITE, SnakeGraphics::Left);
	Locator::GetGraphics()->PlotText(Game::World_Width / 2 - 4, Game::World_Height / 2 + 2, 0,	BLACK, L"Quit",		WHITE, SnakeGraphics::Left);

	switch (n) 
	{
	case 0:
		Locator::GetGraphics()->PlotText(Game::World_Width / 2 - 4, Game::World_Height / 2, 1,		RANDOMCOLOR, L"Play",	WHITE, SnakeGraphics::Left);
		break;
	case 1:
		Locator::GetGraphics()->PlotText(Game::World_Width / 2 - 5, Game::World_Height / 2 + 1, 1,	RANDOMCOLOR, L"About", WHITE, SnakeGraphics::Left);
		break;
	case 2:
		Locator::GetGraphics()->PlotText(Game::World_Width / 2 - 4, Game::World_Height / 2 + 2, 1,	RANDOMCOLOR, L"Quit",	WHITE, SnakeGraphics::Left);
		break;
	default:
		std::cout << "selected menuitem is outside acceptable range {render: MenuState} \n";
		break;
	}

	RenderBorder();
}

void MenuState::RenderBorder()
{
	for (int x = 0; x < Locator::GetGraphics()->GetNumColumns(); x++)
	{
		Locator::GetGraphics()->PlotTile(x, 0, 0, BLUE, BLUE, ' ');

		Locator::GetGraphics()->PlotTile(x, Locator::GetGraphics()->GetNumRows() - 1, 0, BLUE, BLUE, ' ');
	}

	for (int y = 0; y < Locator::GetGraphics()->GetNumRows(); y++)
	{
		Locator::GetGraphics()->PlotTile(0, y, 0, BLUE, BLUE, ' ');

		Locator::GetGraphics()->PlotTile(Locator::GetGraphics()->GetNumColumns() - 1, y, 0, BLUE, BLUE, ' ');
	}
}

void MenuState::CleanUp()
{
	for (int x = 0; x < Locator::GetGraphics()->GetNumColumns(); x++)
	{
		for (int y = 0; y < Locator::GetGraphics()->GetNumRows(); y++)
		{
			Locator::GetGraphics()->PlotTile(x, y, 0, BLACK, BLACK, ' ');

			Locator::GetGraphics()->PlotTile(x, y, 1, BLACK, BLACK, ' ');
		}
	}
}

void MenuState::KeyDown(int Key)
{
	switch (Key)
	{
	case 13:
		//Enter

		switch (n) {
	case 0:
				Locator::GetStateMachine()->ChangeState(new GameState());
				break;
			case 2:
				DestroyWindow(Locator::GetGraphics()->Hwnd);
				break;
		}
		break;
	case 87:
	case 38:
		//Up
		n--;
		if (n < 0) n = 2;
		break;
	case 83:
	case 40:
		//Down
		n++;
		if (n > 2) n = 0;
		break;
	case 27:
		DestroyWindow(Locator::GetGraphics()->Hwnd);
		break;
	default:
		std::cout << Key << "\n";
		break;
	}

}


