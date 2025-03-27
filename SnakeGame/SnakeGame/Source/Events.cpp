#include "Events.h"

void Subject::AddObserver(Observer* observer)
{
	observers.push_back(observer);
}

void Subject::RemoveObserver(Observer* observer)
{
	auto it = std::find(observers.begin(), observers.end(), observer);
	if (it != observers.end())
	{
		observers.erase(it);
	}
}
