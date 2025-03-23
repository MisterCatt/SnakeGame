#pragma once
#include "BaseState.h"
class GameState : public BaseState
{
	// Inherited via BaseState
	bool Init() override;
	void Update() override;
	void Render() override;
	void CleanUp() override;
	void KeyDown(int Key) override;
};

