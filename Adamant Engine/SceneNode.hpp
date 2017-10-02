#pragma once

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

enum Layer
{
	Background,
	Air,
	LayerCount,
};

class SceneNode : 
	public sf::Drawable,
	private sf::NonCopyable,
	public sf::Transformable
{
public:
	typedef std::unique_ptr<SceneNode> Node;
private:
	std::vector<Node> children;
	SceneNode* parent = nullptr;
public:
	SceneNode();
	~SceneNode();
	
	void attachChild(Node child);
	Node detachChild(const SceneNode& node);

	void update(sf::Time dt);

	sf::Transform getWorldTransform() const;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void updateCurrent(sf::Time dt);
	void updateChildren(sf::Time dt);
};

