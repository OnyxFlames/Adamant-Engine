#include "Tank.hpp"



Tank::Tank(const TextureHolder& textures)
	: Object(textures)
{
	object.setTexture(textures.get(Textures::ForestTank));
}


Tank::~Tank()
{
}

void Tank::update(sf::Time delta)
{
	object.move(velocity.x * delta.asMilliseconds(), velocity.y * delta.asMilliseconds());
}

void Tank::draw(sf::RenderTarget & target)
{
	target.draw(object);
}

void Tank::setVelocity(sf::Vector2f & vel)
{
	velocity = vel;
}
