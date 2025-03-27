#pragma once
#include "../SnakeLibrary/SnakeGraphics.h"

struct Vector2Int
{
	int x;
	int y;

	bool operator== (const Vector2Int& other) const
	{
		return x == other.x && y == other.y;
	}
};

enum class Direction
{
	Up,
	Down,
	Left,
	Right
};

class GameObject
{
public:
	virtual ~GameObject() = default;

	virtual void Init(Vector2Int position = {20,20});

	virtual void Update();
	virtual void Render();

	virtual void CleanUp();

	Vector2Int GetPosition() const;
	void SetPosition(Vector2Int pos);

	void SetColor(Color color);
	Color GetColor() const;

	void OnDeath() 
	{

	}
public:
	bool isAlive = true;
private:
	Vector2Int position = {0,0};
	Color color;
};

