#pragma once

#include <string>

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Literals.hpp"
#include "ResourceManager.hpp"
#include "World.hpp"

class Application
{
private:
	bool mpaused = false;
	std::string game_title = "";
	sf::RenderWindow window;
	std::unique_ptr<TextureHolder> texture_manager;
	std::unique_ptr<FontHolder> font_manager;
	
	World world;

public:
	Application(sf::Vector2i size, std::string title, bool fullscreen);
	~Application();

	void run();
private:
	void handle_events();
	void update(sf::Time delta);
	void render();
};

