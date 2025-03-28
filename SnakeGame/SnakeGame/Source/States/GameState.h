#pragma once
#include "BaseState.h"
#include "../Game/Snake.h"
#include "../Game/Apple.h"
#include "../Game/World.h"

class StateMachine;

class GameState : public BaseState, public Observer
{
public:
	enum class GameMode { };

	Snake snake;
	Apple apple;

	World world;

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

	float time = 0.0f;

	// Inherited via Observer
	void OnDeath() override;

	void OnAppleCollision() override;
	
};

