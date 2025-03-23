#pragma once
#include "States/BaseState.h"
class StateMachine
{
private:
	BaseState* currentState;
public:
	StateMachine();
	bool Init(BaseState* state);
	void ChangeState(BaseState* nextState);
	void Update();
	void Render();
	void CleanUp();
	void KeyDown(int Key);
};

