#pragma once

#include "Position.hpp"
#include "World.hpp"

/**
 * @brief Movement speed of the sim
 *
 */
#define MOVEMENT_SPEED (2.0f)

/**
 * @brief Sim that will walk through the simulation and collide with other sims
 *
 */
class Sim
{
public:
	/**
	 * @brief Construct a new Sim object
	 *
	 * @param initialHealth Health of the sim
	 * @param radius Radius of the sim
	 * @param spawnPos Spawn position of the sim
	 * @param world World to which the sim belongs
	 */
	Sim(int initialHealth, float radius, Position spawnPos, World world);

	/**
	 * @brief Construct a new Sim object without intialization
	 *
	 */
	Sim();

	/**
	 * @brief Hurt the sim
	 *
	 * @param damage Damage dealt to the sim
	 */
	void hurt(int damage);

	/**
	 * @brief Check if the other position is colliding with this sim
	 *
	 * @param collider Other position that will be checked
	 * @return true True if they are colliding
	 * @return false False if they are not colliding
	 */
	bool checkCollisionRange(Position collider);

	/**
	 * @brief Move the sim
	 *
	 * @param deltaTime Delta time between two frames
	 */
	void move(float deltaTime);

	/**
	 * @brief Get the sprite of the sim
	 *
	 * @return sf::CircleShape Shape that represents this sims sprite
	 */
	sf::CircleShape getSprite();

	/**
	 * @brief Set the jealth of the sim
	 *
	 * @param health Health that will be set
	 */
	void setHealth(int health);

	/**
	 * @brief Set the radius of the sim
	 *
	 * @param radius Radius that will be set
	 */
	void setRadius(int radius);

	/**
	 * @brief Set the position of the sim
	 *
	 * @param pos Position that will be set
	 */
	void setPos(Position pos);

	/**
	 * @brief Set the world of the sim
	 *
	 * @param world World that will be set
	 */
	void setWorld(World world);

	/**
	 * @brief Get the position of the sim
	 *
	 * @return Position Position of the sim
	 */
	Position getPosition(void);

	/**
	 * @brief Check if the sim is dead
	 *
	 * @return true True if the sim is dead
	 * @return false False if the sim is not dead
	 */
	bool isDead(void);

private:
	/**
	 * @brief Current health of the sim
	 *
	 */
	int health;

	/**
	 * @brief Radius of the sim
	 *
	 */
	float radius;

	/**
	 * @brief Position of the sim
	 *
	 */
	Position pos;

	/**
	 * @brief World to which the sim belongs to
	 *
	 */
	World world;

	/**
	 * @brief Shape of the sim
	 *
	 */
	sf::CircleShape shape;
};