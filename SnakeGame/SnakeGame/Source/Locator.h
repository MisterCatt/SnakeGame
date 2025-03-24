#pragma once
#include "StateMachine.h"
#include "SnakeLibrary/SnakeInput.h"

class Locator
{
public:
	static void Initialize();
	static void Terminate();
	static void ProvideGraphics(SnakeGraphics* service);
	static void ProvideStateMachine(StateMachine* service);
	static SnakeGraphics* GetGraphics();
	static StateMachine* GetStateMachine();

private:
	static SnakeGraphics* graphics_;
	static StateMachine* stateMachine_;
};

