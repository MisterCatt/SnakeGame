#include "Snake.h"

#include <iostream>
#include "../Helper.h"
#include "../Locator.h"

void Snake::Init(Vector2Int pos)
{
	GameObject::Init(pos);
	SetColor(GREEN);
	tail.clear();
	isAlive = true;
}

void Snake::Update()
{
	if (!isAlive) return;

	Vector2Int prevPos = GetPosition();
	Vector2Int newPos = prevPos;
	switch (direction)
	{
	case Direction::Up:
		newPos.y--;
		break;
	case Direction::Down:
		newPos.y++;
		break;
	case Direction::Left:
		newPos.x--;
		break;
	case Direction::Right:
		newPos.x++;
		break;
	}
	SetPosition(newPos);

	for (auto& tailPiece : tail)
	{
		Vector2Int temp = tailPiece.GetPosition();
		tailPiece.SetPosition(prevPos);
		prevPos = temp;
	}

	if (CheckCollision()) 
	{
		Death();
		return;
	}
}

void Snake::Render()
{
	GameObject::Render();

	if(tail.size() > 0)
	for (auto& tailPiece : tail)
	{
		tailPiece.Render();
	}
}

void Snake::CleanUp()
{
	GameObject::CleanUp();

	if (tail.size() > 0)
	for (auto& tailPiece : tail)
	{
		tailPiece.CleanUp();
	}
	tail.clear();

	observers.clear();
}

void Snake::SetDirection(Direction dir)
{
	switch (direction) {
	case Direction::Up:
		if (dir == Direction::Down) return;
		break;
	case Direction::Down:
		if (dir == Direction::Up) return;
		break;
	case Direction::Left:
		if (dir == Direction::Right) return;
		break;
	case Direction::Right:
		if (dir == Direction::Left) return;
		break;
	default:
		break;
	}
	direction = dir;
}

void Snake::AddTail()
{
	SnakeTail newTail;
	newTail.Init(GetPosition());
	tail.push_back(newTail);
}

bool Snake::CheckCollision()
{
	for (auto& tailPiece : tail)
	{
		if(GetPosition() == tailPiece.GetPosition())
		{
			return true;
		}
	}

	if (GetPosition().x <= 0
		|| GetPosition().y <= 0
		|| GetPosition().x >= Locator::GetGraphics()->GetNumColumns()
		|| GetPosition().y >= Locator::GetGraphics()->GetNumRows()) 
		return true;

	return false;
}

void Snake::Death()
{
	for (auto& tailPiece : tail)
	{
		tailPiece.isAlive = false;
	}

	isAlive = false;

	Notify();
}

void Snake::Notify()
{
	for (auto& observer : observers)
	{
		observer->OnNotify();
	}
}
