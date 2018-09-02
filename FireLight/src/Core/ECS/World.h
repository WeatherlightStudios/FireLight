#ifndef WORLD_HEADER
#define WORLD_HEADER


#include <vector>
#include <map>

//external Includes
#include <tuple>
#include <utility>
#include <bitset>


//internal Includes
#include "Component.h"



#define MAX_COMPONETNS 1024


using ComponentType = uint32_t;
using ComponentID = uint32_t;
using EntityID = uint32_t;

using Entity = std::pair<EntityID, std::vector<std::pair<ComponentType, ComponentID>>>;

class World;
struct EntityHandler;


class System;


class World
{
public:
	World();
	~World();
	
	
	EntityHandler* CreateEntity();

	void removeEntity(EntityHandler* handler);

	template<class T>
	void addComponent(EntityHandler* handler, T* Component)
	{


		std::map<uint32_t, std::vector<BaseComponent*>>::iterator it;
		it = m_components.find(T::ID);
		std::pair<ComponentType, ComponentID> pair;
		pair.first = T::ID;
		pair.second = m_components[T::ID].size();
		/*HandleToRow(handler)->second.push_back(pair);
		m_components[T::ID].push_back(Component);
		for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
		{
			if ((handler->m_key & m_Game_Systems[i]->getKey()) != m_Game_Systems[i]->getKey())
			{
				m_Game_Systems[i]->registerEntity(handler);
			}
		}*/
	}

	template<class T>
	void removeComponent(EntityHandler* handler)
	{
		for (uint32_t i = 0; i < HandleToRow(handler)->second.size(); i++)
		{
			if (T::ID == HandleToRow(handler)->second[i].first)
			{
				m_components[T::ID].erase(HandleToRow(handler)->second[i].second);
				HandleToRow(handler)->second.erase(HandleToRow(handler)->second.begin() + i);

				//TODO:: rimuovere l'entita dall sistema
			}
		}
	}

	template<class T>
	T* getComponent(EntityHandler* handler)
	{
		for (uint32_t i = 0; i < HandleToRow(handler)->second.size(); i++)
		{
			if (T::ID == HandleToRow(handler)->second[i].first)
			{
				return (T*)m_components[T::ID][HandleToRow(handler)->second[i].second];
			}
		}

		return nullptr;
	}

	BaseComponent* getComponentByID(uint32_t ID, EntityHandler* handler);


	void addBaseSystem();
	void removeBaseSystem();

	void addGameSystem(System* system);
	void removeGameSystem();

	void UpdateBaseSystems();

	void UpdateGameSystems();

private:
	std::vector<System*> m_Game_Systems;
	std::vector<System*> m_Base_Systems;

	std::vector<Entity*> m_Entitys;
	std::map<uint32_t,std::vector<BaseComponent*>> m_components;


	inline Entity* HandleToRow(EntityHandler* entity)
	{
		return (Entity*)entity;
	}



};


struct EntityHandler
{
	World* m_world;
	std::bitset<MAX_COMPONETNS> m_key;

	template<class T>
	void add_Component(T component)
	{
		m_world->addComponent(this, &component);
		//m_key[T::ID] = 1;
	}

};


class System
{
public:
	System();

	void updateEntity();

	virtual void Init() {}

	virtual void updateComponents(std::vector<BaseComponent*> components) {}

	void setWorld(World* world);

	void registerEntity(EntityHandler* entity);

	void deregisterEntity(EntityHandler* entity);

	template<class T>
	void registerComponent()
	{
		m_key[T::ID] = 1;
		componentTypes.push_back(T::ID);
	}

	std::bitset<MAX_COMPONETNS> getKey()
	{
		return m_key;
	}

	int getSize() { return m_Entity.size(); }

	~System();

private:

	std::bitset<MAX_COMPONETNS> m_key;
	std::vector<uint32_t> componentTypes;
	std::vector<EntityHandler*> m_Entity;

	World* m_world;
};



//for test


class TestSystem : public System
{
public:
	void Init();
	void updateComponents(std::vector<BaseComponent*> components);
};

#endif
