#pragma once

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceTypes.hpp"

template <typename Resource, typename Identifier>
class ResourceManager
{
private:
	std::map<Textures::ID,
		std::unique_ptr<sf::Texture>> textureMap;
	std::map<Identifier,
		std::unique_ptr<Resource>> resourceMap;
public:
	ResourceManager();
	~ResourceManager();
	// Old texture specific methods
	void _load(Textures::ID id, const std::string& filename);
	sf::Texture& _get(Textures::ID id);
	const sf::Texture& _get(Textures::ID id) const;
	//...
	template <typename Parameter>
	void load(Identifier id, const std::string& filename, Parameter& secondParam);
	void load(Identifier id, const std::string& filename);
	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;
};

typedef ResourceManager<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceManager<sf::Font, Fonts::ID> FontHolder;
typedef ResourceManager<sf::Sound, Sounds::ID> SoundHolder;

#include "ResourceManager.inl"