#include "Object.hpp"

Object::Object()
{
}

Object::Object(const TextureHolder & textures)
{
}

Object::~Object()
{
}

void Object::update(sf::Time delta)
{
}

void Object::draw(sf::RenderTarget & target)
{
	target.draw(object);
}

ObjectType::ID Object::getType()
{
	return type;
}
