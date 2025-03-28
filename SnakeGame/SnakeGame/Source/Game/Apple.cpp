#include "Apple.h"
#include "../Helper.h"
#include "../Locator.h"

Apple::Apple()
{
}

Apple::~Apple()
{
}

void Apple::Init(Vector2Int position)
{
	GameObject::Init(position);
	SetColor(RED);
	isAlive = true;


	while (Locator::GetWorld()->at(position.y * 60 + position.x) != 0)
	{
		position = Vector2Int{ (rand() % (Locator::GetGraphics()->GetNumColumns() - 2)) + 1,(rand() % (Locator::GetGraphics()->GetNumRows() - 2)) + 1 };
	}

	Locator::GetWorld()->at(position.y * 60 + position.x) = static_cast<short>(2);
}

void Apple::ChangePosition(Vector2Int pos)
{
	Locator::GetWorld()->at(pos.y * 60 + pos.x) = static_cast<short>(0);
	SetPosition(pos);
	Locator::GetWorld()->at(pos.y * 60 + pos.x) = static_cast<short>(2);
}
