#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in):
	manager(hwnd)
{
	window = hwnd;
	input = in;

	// initialise game objects

	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	ball.setSize(sf::Vector2f(100, 100));
	ball.setPosition(100, 100);
	ball.setTexture(&ballTexture);
	ball.setInput(input);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball.handleInput(dt);

	if (input->isKeyDown(sf::Keyboard::Space))
	{
		manager.spawn();
	}

}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);
	manager.update(dt, window);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
	manager.render(window);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}