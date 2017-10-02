#include "World.hpp"



World::World(sf::RenderWindow& window)
	:	window(window)
	,	worldView(window.getDefaultView())
	,	worldBounds(
			0.f,
			0.f,
			worldView.getSize().x,
			2000.f)
	, spawnPosition(
		worldView.getSize().x / 2,
		worldBounds.height - worldView.getSize().y
	)
{
}


World::~World()
{
}
