#include "GameObject.h"
#include "../Locator.h"
#include "../Helper.h"

void GameObject::Init(Vector2Int position)
{
	SetColor(WHITE);
	SetPosition(position);

	isAlive = true;
}

void GameObject::Update()
{
}

void GameObject::CleanUp()
{
}

Vector2Int GameObject::GetPosition() const
{
	return position;
}

void GameObject::SetPosition(Vector2Int pos)
{
	position = pos;
}

void GameObject::SetColor(Color col)
{
	color = col;
}

Color GameObject::GetColor() const
{
	return color;
}
