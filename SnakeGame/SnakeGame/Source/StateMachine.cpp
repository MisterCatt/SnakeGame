#include "StateMachine.h"
#include "SnakeLibrary/SnakeInput.h"
#include <iostream>

#include "Locator.h"

StateMachine::StateMachine() : currentState(nullptr){

}

bool StateMachine::Init(BaseState* state)
{
	SnakeInput::AddKeyDownCallback(std::bind(&StateMachine::KeyDown, this, std::placeholders::_1));

	currentState = state;
	currentState->Init();
	return false;
}

void StateMachine::ChangeState(BaseState* nextState)
{
	currentState->CleanUp();
	delete currentState;
	currentState = nextState;
	currentState->Init();
}

void StateMachine::Update()
{
	currentState->Update();
}

void StateMachine::Render()
{
	currentState->Render();
}

void StateMachine::CleanUp()
{
	SnakeInput::CleanUp();
	delete currentState;
	currentState = nullptr;
}

void StateMachine::KeyDown(int Key)
{
	currentState->KeyDown(Key);
}
