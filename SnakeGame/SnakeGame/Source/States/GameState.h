#pragma once
#include "BaseState.h"
#include "../Game/Snake.h"
#include "../Game/Apple.h"

class StateMachine;

class GameState : public BaseState, public Observer
{
public:
	enum class GameMode { };

	static StateMachine* stateMachine;

	Snake snake;
	Apple apple;

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

	void ChangeToMenu();

	int level = 0;
	int players = 1;

	bool playerIsDead = false;

	// Inherited via Observer
	void OnNotify() override;

};

