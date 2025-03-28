#pragma once
#include <vector>

#include "Game/GameObject.h"

class Observer 
{
public:
	virtual ~Observer() = default;
	virtual void OnDeath() = 0;
	virtual void OnAppleCollision() = 0;
};

class Subject
{
public:
	virtual ~Subject() = default;
	virtual void AddObserver(Observer* observer);
	virtual void RemoveObserver(Observer* observer);
	virtual void OnDeath() = 0;
	virtual void OnCollideWithApple(Vector2Int position) = 0;

protected:
	std::vector<Observer*> observers;

};