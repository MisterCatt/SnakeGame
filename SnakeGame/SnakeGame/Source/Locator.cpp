#include "Locator.h"

SnakeGraphics* Locator::graphics_ = nullptr;
StateMachine* Locator::stateMachine_ = nullptr;

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
