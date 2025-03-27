#pragma once
#include <vector>
class Observer 
{
public:
	virtual ~Observer() = default;
	virtual void OnNotify() = 0;
};

class Subject
{
public:
	virtual ~Subject() = default;
	virtual void AddObserver(Observer* observer);
	virtual void RemoveObserver(Observer* observer);
	virtual void Notify() = 0;

protected:
	std::vector<Observer*> observers;

};