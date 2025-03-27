#pragma once
#include "GameObject.h"
#include "SnakeTail.h"
#include "../Events.h"

class Snake : public GameObject, public Subject
{
public:
	void Init(Vector2Int position = { 20,20 });

	void Update() override;
	void Render() override;

	void CleanUp() override;

	void SetDirection(Direction dir);

	void AddTail();

	bool CheckCollision();

	void Death();
private:
	Direction direction = Direction::Right;
	std::vector<SnakeTail> tail;

	void Notify() override;
};

