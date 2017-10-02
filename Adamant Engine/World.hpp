#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "Object.hpp"
#include "ResourceTypes.hpp"

typedef std::unique_ptr<Object> ObjectPtr;
typedef std::vector<ObjectPtr> ObjectList;

class World
{
private:
	ObjectList objects;
	std::unique_ptr<TextureHolder> mtextures;
	std::unique_ptr<SoundHolder> msounds;
	std::unique_ptr<FontHolder> mfonts;
public:
	World();
	~World();

	void load_resources();

	void update(sf::Time delta);
	void draw(sf::RenderTarget& target);
	void spawnObject(ObjectType::ID id);
};

