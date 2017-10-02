#include "SelectList.hpp"



SelectList::SelectList(FontHolder& fonts)
{
	reference_text.setFont(fonts.get(Fonts::Console));
	reference_text.setCharacterSize(11);
	reference_text.setFillColor(sf::Color::White);
}


SelectList::~SelectList()
{
}

void SelectList::add_element(const std::string _element)
{
	elements.push_back(_element);
}

void SelectList::update(sf::Time dt)
{
	static sf::Time elapsed = sf::seconds(0);
	elapsed += dt;
	if (elapsed.asSeconds() < 1.0f)
		return;
	else
	{
		if (elements.size() > 0)
			element_texts.clear();
		for (const auto& elem : elements)
		{
			sf::Text temp_text;
			temp_text = reference_text;
			temp_text.setString(elem);
			element_texts.push_back(temp_text);
		}
	}
}

void SelectList::draw(sf::RenderTarget & target)
{
	for (const auto& elem : element_texts)
		target.draw(elem);
}
