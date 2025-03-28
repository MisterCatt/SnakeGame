#pragma once
#include "GameObject.h"
#include "SnakeTail.h"
#include "../Events.h"

class Snake : public GameObject, public Subject
{
public:
	void Init(Vector2Int position = { 20,20 });

	void Update() override;

	void CleanUp() override;

	void SetDirection(Direction dir);

	void AddTail();

	bool CheckCollision(Vector2Int pos) const;

	void Death();

	void Reset();
private:
	Direction direction = Direction::Right;
	std::vector<SnakeTail> tail;

	Vector2Int spawnPosition = {20,20};

	void OnDeath() override;
	void OnCollideWithApple(Vector2Int position) override;
};

