#pragma once
#include "BaseState.h"
#include "../Game/Snake.h"

class StateMachine;

class GameState : public BaseState
{
public:
	enum class GameMode { };

	static StateMachine* stateMachine;

	Snake snake;

	bool isPaused = false;
public:
	// Inherited via BaseState
	bool Init() override;
	void Update() override;
	void Render() override;
	void CleanUp() override;
	void KeyDown(int Key) override;
private:
	void RenderBorder();

	int level = 0;
	int players = 1;

};

