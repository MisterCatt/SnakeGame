#include "Locator.h"

SnakeGraphics* Locator::graphics_ = nullptr;
StateMachine* Locator::stateMachine_ = nullptr;
std::vector<short>* Locator::world_;
float Locator::deltaTime = 0.0f;

void Locator::Initialize()
{
	graphics_ = nullptr;
	stateMachine_ = nullptr;
}

void Locator::Terminate()
{
	graphics_ = nullptr;
	stateMachine_ = nullptr;
}

void Locator::ProvideGraphics(SnakeGraphics* service)
{
	graphics_ = service;
}

void Locator::ProvideStateMachine(StateMachine* service)
{
	stateMachine_ = service;
}

SnakeGraphics* Locator::GetGraphics()
{
	return graphics_;
}

StateMachine* Locator::GetStateMachine()
{
	return stateMachine_;
}

void Locator::ProvideWorld(std::vector<short>* service)
{
	world_ = service;
}

std::vector<short>* Locator::GetWorld()
{
	return world_;
}

void Locator::SetDeltaTime(float dt)
{
	deltaTime = dt;
}

float Locator::GetDeltaTime()
{
	return deltaTime;
}
