#include "ResourceManager.hpp"




// Old texture specific load files
// To be replaced shortly
template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::_load(Textures::ID id, const std::string & filename)
{
	std::unique_ptr<sf::Texture> texture(new sf::Texture());
	if (!texture->loadFromFile(filename))
	{
		throw std::runtime_error("Failed to load texture \"" + filename + "\" ID: " + std::to_string(id));
	}

	textureMap.insert(std::make_pair(id, std::move(texture)));
}

template <typename Resource, typename Identifier>
sf::Texture& ResourceManager<Resource, Identifier>::_get(Textures::ID id)
{
	auto found = textureMap.find(id);
	return *found->second;
}

template <typename Resource, typename Identifier>
const sf::Texture & ResourceManager<Resource, Identifier>::_get(Textures::ID id) const
{
	auto found = textureMap.find(id);
	return *found->second;
}