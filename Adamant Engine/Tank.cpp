#include "Tank.hpp"

Tank::Tank(Type type, const TextureHolder & textures) 
	:	type(type), sprite(textures.get(toTextureID(Tank::Type::Forest)))
{
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

Tank::~Tank()
{
}

void Tank::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
