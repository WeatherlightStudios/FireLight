#pragma once

#include<tuple>
#include<vector>
#include<bitset>
#include<iostream>

using ComponentType = uint32_t;
using ComponentID = uint32_t;
using EntityID = uint32_t;


//using Entity = std::tuple<EntityID, std::vector<std::pair<ComponentType, ComponentID>>, std::bitset<1024>>;

class Entity
{
public:
	Entity();

	void addComponent(uint32_t ID);

	void removeComponent(uint32_t ID);

	std::bitset<150> getKey();

	void setID(uint32_t ID);

	uint32_t getID();

	~Entity();

private:

	uint32_t m_EntityID;
	std::bitset<150> m_key;
};