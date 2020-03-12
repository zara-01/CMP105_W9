#pragma once
#include "Ball.h"
#include <math.h>
#include <vector>

class BeachBallManager
{

public:

	BeachBallManager(sf::RenderWindow* window);
	~BeachBallManager();

	void spawn();
	void update(float dt, sf::RenderWindow* window);
	void deathCheck(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);

private:

	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;

};

