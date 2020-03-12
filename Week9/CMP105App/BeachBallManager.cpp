#include "BeachBallManager.h"

BeachBallManager::BeachBallManager(sf::RenderWindow* window)
{

	spawnPoint = sf::Vector2f((window->getSize().x/2)-50, (window->getSize().y / 2)-50);
	texture.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 20; i++)
	{

		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));

	}

}

BeachBallManager::~BeachBallManager()
{
}

void BeachBallManager::update(float dt, sf::RenderWindow* window)
{

	// call update on the alive balls
	for (int i = 0; i < balls.size(); i++)
	{

		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}

		deathCheck(window);
	}

}

// spawn new ball
// find a dead ball, make alive, move to spawna and give random 
void BeachBallManager::spawn()
{

	for (int i = 0; i < balls.size(); i++)
	{

		if (!balls[i].isAlive())
		{

			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			return;

		}

	}

}

// cheack all ALIVE balls to see if outscreen screen/range, if so make dead
void BeachBallManager::deathCheck(sf::RenderWindow* window)
{

	for (int i = 0; i < balls.size(); i++)
	{
		if(balls[i].isAlive())
		{
			if (balls[i].getPosition().x < -100) 
			{ 
				balls[i].setAlive(false);
			}

			if (balls[i].getPosition().x > window->getSize().x)
			{
				balls[i].setAlive(false); 
			}

			if (balls[i].getPosition().y < -100) 
			{
				balls[i].setAlive(false); 
			}

			if (balls[i].getPosition().y > window->getSize().y) 
			{
				balls[i].setAlive(false); 
			}
		}
	}

}

// render all alive balls 

void BeachBallManager::render(sf::RenderWindow* window)
{

	for (int i = 0; i < balls.size(); i++)
	{

		if (balls[i].isAlive())
		{

			window->draw(balls[i]);

		}

	}

}