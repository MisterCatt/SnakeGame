#pragma once
#include "StateMachine.h"
#include "Game/World.h"
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

	static void ProvideWorld(std::vector<short>* service);
	static std::vector<short>* GetWorld();

	static void SetDeltaTime(float dt);
	static float GetDeltaTime();

private:
	static std::vector<short>* world_;
	static SnakeGraphics* graphics_;
	static StateMachine* stateMachine_;
	static float deltaTime;
};

