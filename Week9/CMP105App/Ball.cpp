#include "Ball.h"

Ball::Ball()
{
	speed = 200.f;
	x = speed;
	y = speed;
	velocity = sf::Vector2f(x, y);
}

Ball::~Ball()
{
}

void Ball::update(float dt)
{

	move(velocity * dt);

}
