#pragma once

#include "Position.hpp"

/**
 * @brief World that contains all sims
 *
 */
class World
{
public:
	/**
	 * @brief Construct a new world with size
	 *
	 * @param x Horizontal size of the world
	 * @param y Vertical size of the world
	 */
	World(int x, int y);

	/**
	 * @brief Construct a new world
	 *
	 */
	World();

	/**
	 * @brief Get the a new random position within the bounds of the world
	 *
	 * @return Position Random position within the bounds of the world
	 */
	Position getRandomPos(void);

	/**
	 * @brief Check if a position is within the bounds of the world
	 *
	 * @param pos Position that will be checked
	 * @return true True if the position is within the bounds of the world
	 * @return false False if the position is not within the bounds of the world
	 */
	bool inWorld(Position pos);

private:
	/**
	 * @brief Horizontal size of the world
	 *
	 */
	int sizeX;

	/**
	 * @brief Vertical size of the world
	 *
	 */
	int sizeY;
};