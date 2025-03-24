#pragma once
#include "GameObject.h"

class Snake;

class SnakeTail : GameObject
{
public:
	enum Direction { Up = 0, Down = 1, Left = 2, Right = 3};
	Direction direction = Direction::Left;

	SnakeTail(SnakeTail* previous = nullptr);
	void Update() override;

	GameObject* head_ = nullptr;
	GameObject* previous_ = nullptr;
};

