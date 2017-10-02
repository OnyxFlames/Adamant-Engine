#pragma once
/*
	Basic game object. Only contains a sprite, and update and draw functions;
*/

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"

class Object
{
private:

protected:
	ObjectType::ID type;
	sf::Sprite object;
public:
	Object();
	Object(const TextureHolder& textures);
	~Object();
	virtual void update(sf::Time delta);
	virtual void draw(sf::RenderTarget &target);
	ObjectType::ID getType();
};

