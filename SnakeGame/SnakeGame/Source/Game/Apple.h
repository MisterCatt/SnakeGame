#pragma once
#include "GameObject.h"
class Apple : public GameObject
{
public:
	Apple();
	~Apple();

	void Init(Vector2Int position = { 20,20 }) override;

	void ChangePosition(Vector2Int pos);
};

