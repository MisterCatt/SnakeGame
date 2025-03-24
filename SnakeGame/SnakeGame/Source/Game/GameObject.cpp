#include "GameObject.h"
#include "../SnakeLibrary/SnakeGraphics.h"
#include "../Locator.h"
#include "../Helper.h"

void GameObject::Render()
{
	if (destroyed) return;

	Locator::GetGraphics()->PlotTile(position.x, position.y, 0, RED, RED, ' ');
}

void GameObject::Destroy()
{
	destroyed = true;
}

bool GameObject::isDestroyed() const
{
	return destroyed;
}
