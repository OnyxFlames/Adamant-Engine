#include "Entity.hpp"



Entity::Entity()
{
}


Entity::~Entity()
{
}

void Entity::setVelocity(sf::Vector2f &velocity)
{
	this->velocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	velocity = sf::Vector2f(vx, vy);
}

sf::Vector2f Entity::getVelocity() const
{
	return velocity;
}

void Entity::updateChildren(sf::Time dt)
{
	move(velocity * dt.asSeconds());
}
