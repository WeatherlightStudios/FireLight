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




//Macros
using ComponentType = uint32_t;
using ComponentID = uint32_t;
using EntityID = uint32_t;

using Entity = std::tuple<EntityID, std::vector<std::pair<ComponentType, ComponentID>>, std::bitset<1024>*>;


class System;


//
class World;
struct EntityHandler
{
	template<class T, class... Args>
	void add_Component(Args... args)
	{
		T* component = new T(args...);
		World::addComponent(this, component);
	}

	template<class T>
	T* getComponent()
	{
		return 	World::getComponentInternal<T>(this);
	}


};


//class System
//{
//public:
//	System();
//
//	void InitAllEntity();
//	void updateEntity();
//	void Draw();
//
//
//
//	virtual void Init() {}
//	virtual void InitEntity(std::vector<BaseComponent*> components) {}
//
//	virtual void Update(std::vector<BaseComponent*> components) {}
//
//	virtual void Render(std::vector<BaseComponent*> components) {}
//
//	void registerEntity(EntityHandler* entity);
//
//	void deregisterEntity(EntityHandler* entity);
//
//	template<class T>
//	void registerComponent()
//	{
//		(*m_key)[T::ID] = 1;
//		componentTypes.push_back(T::ID);
//	}
//
//	std::bitset<1024>* getKey()
//	{
//		return m_key;
//	}
//
//	int getSize() { return m_Entity.size(); }
//
//	~System();
//
//private:
//
//	std::bitset<1024>* m_key;
//	std::vector<uint32_t> componentTypes;
//	std::vector<EntityHandler*> m_Entity;
//};

class World
{
public:
	World();
	~World();
	
	
	static EntityHandler* CreateEntity();

	static void removeEntity(EntityHandler* handler);

	template<class T>
	static void addComponent(EntityHandler* handler, T* Component)
	{
		std::pair<ComponentType, ComponentID> pair;
		pair.first = T::ID;
		pair.second = m_components[T::ID].size();
		std::get<1>(*HandleToRow(handler)).push_back(pair);
		m_components[T::ID].push_back(Component);
		//std::get<2>(*HandleToRow(handler))[T::ID] = 1;
		auto EntityKey = std::get<2>(*HandleToRow(handler));
		auto id = T::ID;
		(*EntityKey)[id] = 1;
	


		for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
		{
			
			auto EnttKey = std::get<2>(*HandleToRow(handler));
			auto systemKey = m_Game_Systems[i]->getKey();
			
			auto entKey = *EnttKey;
			auto sestKey = *systemKey;
			
			if ((entKey & sestKey) == sestKey)
			{
				m_Game_Systems[i]->registerEntity(handler);
			}
			
		}
	}

	template<class T>
	static void removeComponent(EntityHandler* handler)
	{
		for (uint32_t i = 0; i < HandleToRow(handler)->second.size(); i++)
		{
			if (T::ID == HandleToRow(handler)->second[i].first)
			{
				m_components[T::ID].erase(HandleToRow(handler)->second[i].second);
				HandleToRow(handler)->second.erase(HandleToRow(handler)->second.begin() + i);


				for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
				{
					m_Game_Systems[i]->deregisterEntity(handler);
				}
			}
		}
	}

	template<class T>
	static T* getComponentInternal(EntityHandler* handler)
	{
		for (uint32_t i = 0; i < std::get<1>(*HandleToRow(handler)).size(); i++)
		{
			if (T::ID == std::get<1>(*HandleToRow(handler))[i].first)
			{
				return (T*)m_components[T::ID][std::get<1>(*HandleToRow(handler))[i].second];
			}
		}

		return nullptr;
	}

	static BaseComponent* getComponentByID(uint32_t ID, EntityHandler* handler);



	static void addGameSystem(System* system);
	static void removeGameSystem(System* system);

	static void InitGameSystems();
	static void UpdateGameSystems();
	static void RenderGameSystems();

private:
	static std::vector<System*> m_Game_Systems;

	static std::vector<Entity*> m_Entitys;
	static std::map<uint32_t,std::vector<BaseComponent*>> m_components;


	static inline Entity* HandleToRow(EntityHandler* entity)
	{
		return (Entity*)entity;
	}
};



#endif
