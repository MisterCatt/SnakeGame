#pragma once
#include "SnakeLibrary/SnakeGraphics.h"

class GraphicsLocator
{
public:
	static SnakeGraphics* getGraphics() { return service_; }

	static void provide(SnakeGraphics* service)
	{
		service_ = service;
	}
private:
	static SnakeGraphics* service_;
};

