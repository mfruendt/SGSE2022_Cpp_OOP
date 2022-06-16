#include "World.hpp"
#include "Position.hpp"

World::World(int x, int y) :
	sizeX(x),
	sizeY(y)
{
}

World::World()
{
}

bool World::inWorld(Position pos)
{
	return pos.x >= 0 && pos.x < sizeX && pos.y >= 0 && pos.y < sizeY;
}

Position World::getRandomPos(void)
{
	int spawnX = rand() % sizeX;
	int spawnY = rand() % sizeY;

	return Position(spawnX, spawnY);
}