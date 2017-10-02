#pragma once

#include <vector>
#include <string>
#include <experimental/filesystem>

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "Object.hpp"

class SelectList : public Object
{
private:
	std::vector<std::string> elements;

	sf::Font font;
	
	std::vector<sf::Text> element_texts;
	sf::Text reference_text;

public:
	SelectList(FontHolder& fonts);
	~SelectList();
	void add_element(const std::string _element);
	virtual void update(sf::Time dt);
	virtual void draw(sf::RenderTarget& target);
};

