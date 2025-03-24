#pragma once

struct Vector2Int
{
	int x;
	int y;

	bool operator== (const Vector2Int& other) const
	{
		return x == other.x && y == other.y;
	}
};

class GameObject
{
public:
	virtual ~GameObject() = default;

	void init(Vector2Int pos);
	virtual void Update() = 0;
	virtual void Render();
	void Destroy();
	bool isDestroyed() const;
	Vector2Int getPosition() const { return position; }
protected:
	bool destroyed = false;
	Vector2Int position = {0,0};

};

