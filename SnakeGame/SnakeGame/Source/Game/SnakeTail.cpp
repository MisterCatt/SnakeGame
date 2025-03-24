#include "SnakeTail.h"

#include <iostream>

#include "Snake.h"

SnakeTail::SnakeTail(SnakeTail* previous)
{
	previous_ = previous;
}

void SnakeTail::Update()
{
	switch (direction) {
	case Up:
		position.y--;
		break;
	case Down:
		position.y++;
		break;
	case Left:
		position.x--;
		break;
	case Right:
		position.x++;
		break;
	default:
		std::cout << "Invalid direction\n";
		break;
	}

	if (previous_ == head_)
	{
		direction = dynamic_cast<Snake*>(previous_)->direction;
	}
	else
	{
		direction = dynamic_cast<SnakeTail*>(previous_)->direction;
	}
}
