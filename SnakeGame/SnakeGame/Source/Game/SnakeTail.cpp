#include "SnakeTail.h"

#include "../Helper.h"
#include "../Locator.h"

void SnakeTail::Init(Vector2Int position)
{
	GameObject::Init(position);
	SetColor(GREEN);
	Locator::GetWorld()->at(position.y * 60 + position.x) = static_cast<short>(3);
}
