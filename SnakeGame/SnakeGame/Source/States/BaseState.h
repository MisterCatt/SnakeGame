#pragma once
class BaseState
{
public:
	virtual ~BaseState() = default;
	virtual bool Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void CleanUp() = 0;
	virtual void KeyDown(int Key) = 0;
};

