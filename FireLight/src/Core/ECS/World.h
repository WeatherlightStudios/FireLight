#ifndef WORLD_H
#define	WORLD_H

#include <unordered_map>
#include <map>
#include <algorithm>


#include "ComponentPool.h"
#include "Component.h"
#include "System.h"
#include "Entity.h"


struct EntityHandler
{
	template<class T, class... Args>
	void add_Component(Args... args)
	{
		World::addComponent<T>(this, args...);
	}
};


class World
{
public:
	World();

	static EntityHandler* CreateEntity();
	void RemoveEntity(EntityHandler* entity);

	template<class T, class... Args>
	static void addComponent(EntityHandler* entity, Args... args)
	{
		Entity* temp_entity = HandlerToRow(entity);
		m_Components[T::ID].addComponent<T>(temp_entity->getID(), args...);
		temp_entity->addComponent(T::ID);
		checkEntityToSystem(entity);
	}

	template<class T>
	static T* getComponent(uint32_t entityID)
	{
		return &m_Components[T::ID].getComponent<T>(entityID);
	}



	//TODO:: Change Name
	static void checkEntityToSystem(EntityHandler* entity);

	template<class Component>
	void removeComponent(EntityHandler* entity)
	{
		entity->removeComponent(Component::ID);	
		m_Components[Component::ID].removeComponent<Component>(entity->getID());

		removeEntityFromSystem(entity);
	}


	//TODO:: Change Name
	void removeEntityFromSystem(EntityHandler* entity);

	//void addSystem(System* system);
	//void removeSystem(System* system);

	//void UpdateSystems();

	static void addGameSystem(System* system);
	static void removeGameSystem(System* system);

	static void addEngineSystem(System* system);
	static void removeEgnineSystem(System* system);

	static void UpdateGameSystems();
	static void UpdateEngineSystems();

	static int getGameSystemSize() { return m_Game_Systems.size(); }
	static int getEngineSystemSize() { return m_Engine_Systems.size(); }
	static int getEntitySize() { return m_Entitys.size();  }

	static int getComponentSize() { return m_Components.size(); }

	static int getComponentPoolSize(uint32_t ID, size_t size) { return m_Components[ID].Size(size); }

	~World();

private:
	static inline Entity* HandlerToRow(EntityHandler* handler)
	{
		return (Entity*)handler;
	}

	static std::vector<Entity*> m_Entitys;
	static std::vector<System*> m_Game_Systems;
	static std::vector<System*> m_Engine_Systems;

	static std::map<uint32_t, ComponentPool> m_Components;



};

#endif
