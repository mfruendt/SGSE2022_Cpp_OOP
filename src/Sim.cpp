#include "Sim.hpp"
#include "Position.hpp"
#include "World.hpp"
#include <cmath>
#include <stdlib.h>

Sim::Sim(int initialHealth, float radius, Position spawnPos, World world) :
	health(initialHealth),
	radius(radius),
	pos(spawnPos),
	world(world),
	shape(radius)
{
	shape.setFillColor(sf::Color::White);
}

Sim::Sim()
{
	shape.setFillColor(sf::Color::White);
}

void Sim::hurt(int damage)
{
	if (health > 0.0f)
	{
		health -= damage;
	}
}

bool Sim::checkCollisionRange(Position collider)
{
	return pos.x == collider.x && pos.y == collider.y;
}

sf::CircleShape Sim::getSprite()
{
	shape.setPosition(pos.x, pos.y);
	return shape;
}

void Sim::move(float deltaTime)
{
	int randomX = rand() % 3;
	int randomY = rand() % 3;
	unsigned int speed = (unsigned int)(MOVEMENT_SPEED * deltaTime);

	if (randomX == 0)
	{
		if (world.inWorld(Position(pos.x + speed, pos.y)))
		{
			pos.x += speed;
		}
	}
	if (randomY == 1)
	{
		if (world.inWorld(Position(pos.x - speed, pos.y)))
		{
			pos.x -= speed;
		}
	}
	if (randomY == 0)
	{
		if (world.inWorld(Position(pos.x, pos.y + speed)))
		{
			pos.y += speed;
		}
	}
	if (randomY == 1)
	{
		if (world.inWorld(Position(pos.x, pos.y - speed)))
		{
			pos.y -= speed;
		}
	}
}

void Sim::setHealth(int health)
{
	this->health = health;
}

void Sim::setRadius(int radius)
{
	this->radius = radius;
	shape.setRadius(radius);
}

void Sim::setPos(Position pos)
{
	this->pos = pos;
}

void Sim::setWorld(World world)
{
	this->world = world;
}

Position Sim::getPosition(void)
{
	return pos;
}

bool Sim::isDead(void)
{
	return health <= 0.0f;
}