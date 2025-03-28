#pragma once
#include <vector>

// This class is responsible for managing the game world
// tiles are represented by numbers
// 0 = empty
// 1 = wall
// 2 = apple
// 3 = snake

//	f(x,y) = y*60+x

class World
{
public:
	World();
	~World();
	void Init();
	void Render() const;
	void CleanUp();

	void ChangeLevel(int n);
private:
	std::vector<short> world;

};

