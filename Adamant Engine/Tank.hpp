#pragma once

/*
	Tank is a test entity and will be used throughout the engines development for fast-paced entity testing and features.
	This class will be used as a blueprint for other Entity subclasses.
*/

#include "Entity.hpp"

#include "ResourceManager.hpp"

class Tank : Entity
{
public:
	enum Type
	{
		Forest,
		Modern,
		Desert,
	};
private:
	typedef ResourceManager<sf::Texture, Textures::ID> TextureHolder;
	Type type;
	sf::Sprite sprite;
public:
	explicit Tank(Type type, const TextureHolder& textures);
	~Tank();
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};

Textures::ID toTextureID(Tank::Type type)
{
	switch (type)
	{
	case Tank::Forest:
		return Textures::ForestTank;
		break;
	case Tank::Modern:
		return Textures::ModernTank;
		break;
	case Tank::Desert:
		return Textures::DesertTank;
		break;
	default:
		throw std::runtime_error("Tanktype doesn't exist!");
		break;
	}
}

