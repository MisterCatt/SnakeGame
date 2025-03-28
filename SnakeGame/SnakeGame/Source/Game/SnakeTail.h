#pragma once
#include "GameObject.h"

class Snake;

class SnakeTail : public GameObject
{
public:
	void Init(Vector2Int position = { 20,20 }) override;
	void CleanUp() override;
};

