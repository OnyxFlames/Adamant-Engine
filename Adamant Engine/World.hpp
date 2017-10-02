#pragma once

#include <array>

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "SceneNode.hpp"
#include "Tank.hpp"

typedef ResourceManager<sf::Texture, Textures::ID> TextureHolder;

class World : private sf::NonCopyable
{
public:
	World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();
	~World();
private:
	void loadTextures();
	void buildScene();

private:
	enum Layer {
		Background,
		Air,
		LayerCount,
	};
	sf::RenderWindow& window;
	sf::View worldView;
	TextureHolder Textures;
	SceneNode sceneGraph;
	std::array<SceneNode*, LayerCount> sceneLayers;
	sf::FloatRect worldBounds;
	sf::Vector2f spawnPosition;
	float scrollSpeed;
	Tank* playerTank;
};
