#pragma once
#include "BaseState.h"
class GameState : public BaseState
{
public:
	// Inherited via BaseState
	bool Init() override;
	void Update() override;
	void Render() override;
	void CleanUp() override;
	void KeyDown(int Key) override;
private:
	void RenderBorder();
};

