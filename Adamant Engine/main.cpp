

#include <SFML/Graphics.hpp>

#include "Application.hpp"

#include "ResourceManager.hpp"

#include "tinyxml2/tinyxml2.h"

int main()
{
	Application app(sf::Vector2i(1280, 720), "Adamant Engine", false);
	app.run();

	return 0;
}
