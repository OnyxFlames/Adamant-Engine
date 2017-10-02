#include "Application.hpp"



Application::Application(sf::Vector2i size, std::string title, bool fullscreen = false)
{
	if (fullscreen)
		window.create(sf::VideoMode(size.x, size.y), title, sf::Style::Fullscreen);
	else
		window.create(sf::VideoMode(size.x, size.y), title, sf::Style::Close);
	game_title = title;

	world.load_resources();
}


Application::~Application()
{
}

void Application::run()
{
	sf::Clock t;
	while (window.isOpen())
	{
		handle_events();
		update(t.restart());
		render();
	}
}

void Application::handle_events()
{
	sf::Event e;
	while (window.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::LostFocus:
			mpaused = true;
			break;
		case sf::Event::GainedFocus:
			mpaused = false;
			break;
		case sf::Event::KeyPressed:
			switch (e.key.code)
			{
			case sf::Keyboard::Escape:
				window.close();
				break;
			case sf::Keyboard::T:
				std::cout << "Spawning tank object!\n";
				world.spawnObject(ObjectType::ForestTank);
				break;
			case sf::Keyboard::L:
				std::cout << "Generating selectlist!\n";
				world.spawnObject(ObjectType::SelectList);
				break;
			}
			break;
		}
	}
}

void Application::update(sf::Time delta)
{
	static sf::Time timestep_elapsed;
	static sf::Time run_time;

	if (mpaused)
		delta = sf::seconds(0);

	timestep_elapsed += delta;
	run_time += delta;
	// It's too soon to update
	if (timestep_elapsed < TIMESTEP)
		return;
	else
	{
		window.setTitle(game_title + " - " + std::to_string(delta.asMilliseconds()) + "ms - Runtime: " + std::to_string((int)run_time.asSeconds()));
		timestep_elapsed = sf::seconds(0);
		world.update(delta);
		// Update objects here
	}
}

void Application::render()
{
	window.clear();
	world.draw(window);
	window.display();
}
