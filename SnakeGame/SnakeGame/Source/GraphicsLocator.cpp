#include "GraphicsLocator.h"

SnakeGraphics* GraphicsLocator::service_ = nullptr;

GraphicsLocator::GraphicsLocator()
{
}

SnakeGraphics* GraphicsLocator::GetGraphics()
{
	return service_;
}

void GraphicsLocator::provide(SnakeGraphics* service)
{
	service_ = service;
}