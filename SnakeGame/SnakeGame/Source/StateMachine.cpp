#include "StateMachine.h"
#include "SnakeLibrary/SnakeInput.h"
#include <iostream>
#include <typeinfo>
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
	

	std::cout << "State changed to " << typeid(*nextState).name() << "\n";
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
	delete currentState;
	currentState = nullptr;
}

void StateMachine::KeyDown(int Key)
{
	currentState->KeyDown(Key);
}
