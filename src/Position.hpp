#pragma once

/**
 * @brief Object that represents a position within the world
 *
 */
class Position
{
public:
	/**
	 * @brief Construct a new position with components
	 *
	 * @param x Horizontal component of the position
	 * @param y Vertical component of the position
	 */
	Position(int x, int y) :
		x(x),
		y(y)
	{}

	/**
	 * @brief Construct a new position
	 *
	 */
	Position()
	{}

	/**
	 * @brief Horizontal component of the position
	 *
	 */
	int x;

	/**
	 * @brief Vertical component of the position
	 *
	 */
	int y;
};