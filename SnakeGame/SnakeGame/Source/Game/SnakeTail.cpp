#include "SnakeTail.h"

#include "../Helper.h"

void SnakeTail::Init(Vector2Int position)
{
	GameObject::Init(position);
	SetColor(GREEN);
}