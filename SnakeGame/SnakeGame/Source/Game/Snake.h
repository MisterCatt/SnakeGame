#pragma once
#include "GameObject.h"
#include "SnakeTail.h"

class Snake : public GameObject
{
public:
	SnakeTail::Direction direction = SnakeTail::Direction::Left;

	void Update() override;

	void AddTail();

	void CleanUp();

	SnakeTail* tail = nullptr;
};

