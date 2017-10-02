#pragma once

#include <SFML/Graphics.hpp>

#include "SceneNode.hpp"

class Entity : SceneNode
{
private:
	sf::Vector2f velocity;
public:
	Entity();
	~Entity();
	void setVelocity(sf::Vector2f& velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
private:
	virtual void updateChildren(sf::Time dt);
};

