#include "StateMachine.h"
#include "States/MenuState.h";

StateMachine::StateMachine() : currentState(nullptr){

}

bool StateMachine::Init()
{
	currentState = new MenuState();
	currentState->Init();
	return false;
}

void StateMachine::ChangeState(BaseState* nextState)
{
	currentState->CleanUp();
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
	delete currentState;
	currentState = nullptr;
}
