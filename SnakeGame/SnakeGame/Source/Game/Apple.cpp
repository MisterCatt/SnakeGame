#include "Apple.h"
#include "../Helper.h"

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
}

void Apple::ChangePosition(Vector2Int pos)
{
	SetPosition(pos);
}
