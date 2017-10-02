#include "World.hpp"

#include <iostream>

#include "Tank.hpp"
#include "SelectList.hpp"

World::World()
{
}


World::~World()
{
}

void World::load_resources()
{
	mtextures = std::make_unique<ResourceManager<sf::Texture, Textures::ID>>();
	msounds = std::make_unique<ResourceManager<sf::Sound, Sounds::ID>>();
	mfonts = std::make_unique<ResourceManager<sf::Font, Fonts::ID>>();

	mtextures->load(Textures::Unknown, "../resources/textures/unknown.png");

	mtextures->load(Textures::ForestTank, "../resources/textures/ForestTank.png");

	mtextures->load(Textures::ModernTank, "../resources/textures/ModernTank.png");

	mtextures->load(Textures::DesertTank, "../resources/textures/DesertTank.png");

	// Can't load fonts for some reason
	mfonts->load(Fonts::Console, "../resources/fonts/consola.ttf");

}

void World::update(sf::Time delta)
{
	for (const auto& obj : objects)
		obj->update(delta);
}

void World::draw(sf::RenderTarget & target)
{
	for (const auto& obj : objects)
		obj->draw(target);
}

void World::spawnObject(ObjectType::ID id)
{
	switch (id)
	{
	case ObjectType::ForestTank:
		objects.push_back(std::make_unique<Object>(Tank(*mtextures)));
		break;
	case ObjectType::SelectList:
		objects.push_back(std::make_unique<Object>(SelectList(*mfonts)));
		break;
	default:
		std::cerr << "Error: failed to spawn object. Unknown ID: " << (int)id << "\n";
		break;
	}
}
