#pragma once
#include "BaseState.h"
#include "../StateMachine.h"
class GameState : public BaseState
{
public:
	enum class GameMode { };

	static StateMachine* stateMachine;


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
};

