#pragma once

class SnakeGraphics;

class GraphicsLocator
{
public:
	static SnakeGraphics* GetGraphics();

	static void provide(SnakeGraphics* service);

private:
	static SnakeGraphics* service_;
};

inline SnakeGraphics* GraphicsLocator::GetGraphics()
{
	return service_;
}

inline void GraphicsLocator::provide(SnakeGraphics* service)
{
	service_ = service;
}
