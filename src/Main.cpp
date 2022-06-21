#include "Platform/Platform.hpp"
#include "Position.hpp"
#include "Sim.hpp"
#include "World.hpp"
#include <stdlib.h>
#include <vector>

/**
 * @brief Number of sims
 *
 */
#define NUM_OF_SIMS (2000)

int frames = 0;

/**
 * @brief Main function of the programm
 *
 * @return int Exit code
 */
int main()
{
	// Create window
	util::Platform platform;
	sf::RenderWindow window;
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	window.create(sf::VideoMode(800.0f * screenScalingFactor, 800.0f * screenScalingFactor), "SGSE_Sim_OOP");
	window.setFramerateLimit(60);
	platform.setIcon(window.getSystemHandle());

	sf::Event event;
	sf::Clock deltaClock;

	// Create world
	World world(1.0 * window.getSize().x, 1.0 * window.getSize().y);

	std::vector<Sim> sims;

	// Create sims
	for (int i = 0; i < NUM_OF_SIMS; i++)
	{
		sims.push_back(Sim(3, 1.0f, world.getRandomPos(), world));
	}

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Clear window and get delta time
		window.clear();
		float dt = deltaClock.restart().asMilliseconds();
		// Iterate over every sim
		for (uint i = 0; i < sims.size(); i++)
		{
			// Move the sim
			sims.at(i).move(dt);
			// Draw the sim
			sims.at(i).draw(window);

			// Iterate over every other sim
			for (uint j = i + 1; j < sims.size(); j++)
			{
				// If the sims collide, apply damage to the sim
				if (sims.at(i).checkCollisionRange(sims.at(j).getPosition()))
				{
					//	sim->hurt(1.0f);
				}
			}
		}
		// Iterate over every sim again (seperate loop to prevent inconcistencies)
		for (int k = sims.size() - 1; k >= 0; k--)
		{
			// If the sim is dead, remove it
			if (sims.at(k).isDead())
			{
				sims.erase(sims.begin() + k);
			}
		}
		// Display window and print delta time
		window.display();
		std::cout << dt << std::endl;

		if (frames++ >= 600)
		{
			window.close();
		}
	}

	return 0;
}
