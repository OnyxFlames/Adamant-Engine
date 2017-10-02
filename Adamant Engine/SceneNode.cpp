#include "SceneNode.hpp"

#include <cassert>
#include <algorithm>

SceneNode::SceneNode()
{
}


SceneNode::~SceneNode()
{
}

void SceneNode::attachChild(Node child)
{
	child->parent = this;
	children.push_back(std::move(child));
}

SceneNode::Node SceneNode::detachChild(const SceneNode & node)
{
	// Borrowed from SFML Game Dev book. Page 57.

	auto found = std::find_if(children.begin(), children.end(),
		[&](Node& n) -> bool {return n.get() == &node; });
	assert(found != children.end());

	Node result = std::move(*found);
	result->parent = nullptr;
	children.erase(found);
	return result;
}

void SceneNode::update(sf::Time dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;
	for (const SceneNode* node = this; node != nullptr; node = node->parent)
	{
		transform = node->getTransform() * transform;
	}
	return transform;
}

void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	drawCurrent(target, states);

	for (const Node& child : children)
	{
		child->draw(target, states);
	}
}

void SceneNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
}

void SceneNode::updateCurrent(sf::Time dt)
{
}

void SceneNode::updateChildren(sf::Time dt)
{
	for (auto& child : children)
	{
		child->update(dt);
	}
}
