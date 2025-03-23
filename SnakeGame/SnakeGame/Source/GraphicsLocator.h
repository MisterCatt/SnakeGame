#pragma once
#include "SnakeLibrary/SnakeGraphics.h"

class GraphicsLocator
{
public:
	static SnakeGraphics* GetGraphics();

	static void provide(SnakeGraphics* service);

private:
	GraphicsLocator();

	static SnakeGraphics* service_;
};