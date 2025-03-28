#include "World.h"

#include <iostream>
#include <fstream>
#include <string>

#include "../Locator.h"
#include "../SnakeLibrary/SnakeGraphics.h"
#include "../Helper.h"

#define FOR(n, size) for(int n = 0; n < size; n++)

World::World()
{
	world.resize((Locator::GetGraphics()->GetNumRows() * Locator::GetGraphics()->GetNumColumns()));
}

World::~World()
{

}

void World::Init()
{
	std::ifstream MyFile("world.txt");

	char b = 0;
	int x = 0;

	while (MyFile.get(b))
	{
		switch (b)
		{
		case 48:
			world[x] = 0;
			break;
		case 49:
			world[x] = 1;
			break;
		default:
			continue;
		}

		x++;
	}

	MyFile.close();

	Locator::ProvideWorld(&world);
}

void World::Render() const
{
	int x = 0;
	int y = 0;

	FOR(n, world.size())
	{
		if (x > 59)
		{
			x = 0;
			y++;
		}

		switch (world[n])
		{
		case 0:
			break;
		case 1:
			Locator::GetGraphics()->PlotTile(x, y, 1, WHITE, WHITE, ' ');
			break;
		case 2:
			Locator::GetGraphics()->PlotTile(x, y, 1, RED, RED, ' ');
			break;
		case 3:
			Locator::GetGraphics()->PlotTile(x, y, 1, GREEN, GREEN, ' ');
			break;
		default: 
			break;
		}

		x++;
	}
}

void World::CleanUp()
{
	world.clear();
	world.shrink_to_fit();
}
