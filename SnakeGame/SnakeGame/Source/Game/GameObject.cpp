#include "GameObject.h"
#include "../SnakeLibrary/SnakeGraphics.h"
#include "../Locator.h"
#include "../Helper.h"

void GameObject::init(Vector2Int pos)
{
	destroyed = false;
	position = pos;
}

void GameObject::Render()
{
	if (destroyed) return;

	Locator::GetGraphics()->PlotTile(position.x, position.y, 1, RED, RED, ' ');
}

void GameObject::Destroy()
{
	destroyed = true;
}

bool GameObject::isDestroyed() const
{
	return destroyed;
}
