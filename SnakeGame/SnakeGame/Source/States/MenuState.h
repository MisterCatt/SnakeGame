#pragma once
#include "BaseState.h"
class MenuState : public BaseState
{
public:
	~MenuState() override;
	bool Init() override;
	void Update() override;
	void Render() override;
	void CleanUp() override;
	void KeyDown(int Key) override;

private:

public:
};

