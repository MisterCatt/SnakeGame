#pragma once
#include <vector>

// This class is responsible for managing the game world
// tiles are represented by numbers
// 0 = empty
// 1 = wall
// 2 = apple
// 3 = snake

class World
{
public:
	World();
	~World();
	void Init();
	void Render() const;
	void CleanUp();
private:
	std::vector<short> world;

};

