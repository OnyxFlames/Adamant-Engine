#pragma once

#include "Object.hpp"

class Tank : public Object
{
private:
	sf::Vector2f velocity;
public:
	Tank(const TextureHolder& textures);
	~Tank();
	virtual void update(sf::Time delta) override;
	virtual void draw(sf::RenderTarget &target) override;

	void setVelocity(sf::Vector2f& vel);
};

