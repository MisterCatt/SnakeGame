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

	Locator::GetWorld()->at(pos.y * 60 + pos.x) = static_cast<short>(3);
}

void Snake::Update()
{
	if (!isAlive) return;


	Vector2Int prevPos = GetPosition();
	Locator::GetWorld()->at(prevPos.y * 60 + prevPos.x) = static_cast<short>(0);
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

	switch (Locator::GetWorld()->at(newPos.y * 60 + newPos.x))
	{
	case 1:
	case 3:
		Death();
		break;
	case 2:
		OnCollideWithApple(newPos);
		break;
	default:
		break;
	}		

	Locator::GetWorld()->at(newPos.y * 60 + newPos.x) = static_cast<short>(3);

	for (auto& tailPiece : tail)
	{
		Vector2Int temp = tailPiece.GetPosition();
		Locator::GetWorld()->at(tailPiece.GetPosition().y * 60 + tailPiece.GetPosition().x) = static_cast<short>(0);
		tailPiece.SetPosition(prevPos);
		Locator::GetWorld()->at(tailPiece.GetPosition().y * 60 + tailPiece.GetPosition().x) = static_cast<short>(3);
		prevPos = temp;
	}


	
}

void Snake::CleanUp()
{
	GameObject::CleanUp();

	if (!tail.empty())
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

bool Snake::CheckCollision(Vector2Int pos) const
{
	switch (Locator::GetWorld()->at(pos.y * 60 + pos.x))
	{
	case 1:
	case 3:
		return true;
	default:
		return false;
	}
}

void Snake::Death()
{
	for (auto& tailPiece : tail)
	{
		tailPiece.isAlive = false;
	}

	isAlive = false;

	OnDeath();
}

void Snake::OnDeath()
{
	for (auto& observer : observers)
	{
		observer->OnDeath();
	}
}

void Snake::OnCollideWithApple(Vector2Int position) 
{
	for (auto& observer : observers)
	{
		AddTail();
		observer->OnAppleCollision();
	}
}
