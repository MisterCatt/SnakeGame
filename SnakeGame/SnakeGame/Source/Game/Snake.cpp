#include "Snake.h"

#include <iostream>

void Snake::Update()
{
	switch (direction)
	{
	case SnakeTail::Up:
		position.y--;
		break;
	case SnakeTail::Down:
		position.y++;
		break;
	case SnakeTail::Left:
		position.x--;
		break;
	case SnakeTail::Right:
		position.x++;
		break;
	default: 
		std::cout << "Invalid direction\n";
		break;
	}

	if (tail == nullptr) return;

	SnakeTail* current = tail;

	while (current != nullptr)
	{
		if (current->previous_ == this) break;

		current->Update();
		current = static_cast<SnakeTail*>(current->previous_);
	}
}

void Snake::AddTail()
{
	
}

void Snake::CleanUp()
{
	
}
