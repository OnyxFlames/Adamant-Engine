#pragma once

#include "ResourceManager.hpp"

template <typename Resource, typename Identifier>
ResourceManager<Resource, Identifier>::ResourceManager()
{
}

template <typename Resource, typename Identifier>
ResourceManager<Resource, Identifier>::~ResourceManager()
{
}

template <typename Resource, typename Identifier>
template<typename Parameter>
void ResourceManager<Resource, Identifier>::load(Identifier id, const std::string & filename, Parameter& secondParam)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename, secondParam))
	{
		throw std::runtime_error("Failed to load resource \"" + filename + "\" ID: " + std::to_string(id));
	}

	resourceMap.insert(std::make_pair(id, std::move(resource)));
}

template <typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::load(Identifier id, const std::string & filename)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename))
	{
		throw std::runtime_error("Failed to load resource \"" + filename + "\" ID: " + std::to_string(id));
	}

	resourceMap.insert(std::make_pair(id, std::move(resource)));
}

template <typename Resource, typename Identifier>
Resource & ResourceManager<Resource, Identifier>::get(Identifier id)
{
	auto found = resourceMap.find(id);
	return *found->second;
}

template <typename Resource, typename Identifier>
const Resource & ResourceManager<Resource, Identifier>::get(Identifier id) const
{
	auto found = resourceMap.find(id);
	return *found->second;
}