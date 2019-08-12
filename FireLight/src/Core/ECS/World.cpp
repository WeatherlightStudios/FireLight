#include "World.h"


std::vector<System*> World::m_Game_Systems;
std::vector<System*> World::m_Engine_Systems;
std::vector<Entity*> World::m_Entitys;
std::vector<ComponentPool> World::m_Components;

World::World()
{
}

EntityHandler* World::CreateEntity()
{
	uint32_t index = m_Entitys.size();
	m_Entitys.emplace_back(new Entity());
	Entity* newEntity = m_Entitys.back();
	newEntity->setID(index);

	EntityHandler* handler = (EntityHandler*)newEntity;
	return handler;
}


void World::checkEntityToSystems(EntityHandler* entity)
{
	Entity* temp_entity = HandlerToRow(entity);

	for (int i = 0; i < m_Game_Systems.size(); i++)
	{
		if ((temp_entity->getKey() & m_Game_Systems[i]->getSystemKey()) == m_Game_Systems[i]->getSystemKey())
		{
			m_Game_Systems[i]->addEntity(temp_entity->getID());
		}
	}

	for (int i = 0; i < m_Engine_Systems.size(); i++)
	{
		if ((temp_entity->getKey() & m_Engine_Systems[i]->getSystemKey()) == m_Engine_Systems[i]->getSystemKey())
		{
			m_Engine_Systems[i]->addEntity(temp_entity->getID());
		}
	}
}


void World::checkEntitysToSystem(System* system)
{
	for (int i = 0; i < m_Entitys.size(); i++)
	{
		Entity* temp_entity = m_Entitys[i];

		if ((temp_entity->getKey() & system->getSystemKey()) == system->getSystemKey())
		{
			system->addEntity(temp_entity->getID());
		}
	}
}

void World::removeEntityFromSystem(EntityHandler* entity)
{
	Entity* temp_entity = HandlerToRow(entity);


	for (int i = 0; i < m_Game_Systems.size(); i++)
	{
		if ((m_Game_Systems[i]->getSystemKey() &  temp_entity->getKey()) != m_Game_Systems[i]->getSystemKey())
		{
			m_Game_Systems[i]->removeEntity(temp_entity->getID());
		}
	}

	for (int i = 0; i < m_Engine_Systems.size(); i++)
	{
		if ((m_Engine_Systems[i]->getSystemKey() &  temp_entity->getKey()) != m_Engine_Systems[i]->getSystemKey())
		{
			m_Engine_Systems[i]->removeEntity(temp_entity->getID());
		}
	}
}

void World::RemoveEntity(EntityHandler* entity)
{
	Entity* temp_entity = HandlerToRow(entity);

	removeEntityFromSystem(entity);
	m_Entitys.erase(std::remove(m_Entitys.begin(), m_Entitys.end(), temp_entity), m_Entitys.end());
}

//void World::addSystem(System* system)
//{
//	m_Systems.push_back(system);
//}
//
//void World::removeSystem(System* system)
//{
//
//	m_Systems.erase(std::remove(m_Systems.begin(), m_Systems.end(), system), m_Systems.end());
//
//	//TODO:: 
//}
//
//
//
//void World::UpdateSystems()
//{
//	for (int i = 0; i < m_Systems.size(); i++)
//	{
//		m_Systems[i]->UpdateComponents();
//	}
//}


void World::addGameSystem(System* system)
{
	m_Game_Systems.push_back(system);
	checkEntitysToSystem(system);
}

void World::removeGameSystem(System* system)
{
	m_Game_Systems.erase(std::remove(m_Game_Systems.begin(), m_Game_Systems.end(), system), m_Game_Systems.end());
}

void World::addEngineSystem(System* system)
{
	m_Engine_Systems.push_back(system);
	checkEntitysToSystem(system);
}


void World::removeEgnineSystem(System* system)
{
	m_Engine_Systems.erase(std::remove(m_Engine_Systems.begin(), m_Engine_Systems.end(), system), m_Engine_Systems.end());
}

void World::UpdateGameSystems()
{
	for (int i = 0; i < m_Game_Systems.size(); i++)
	{
		m_Game_Systems[i]->UpdateComponents();
	}
}

void World::UpdateEngineSystems()
{
	for (int i = 0; i < m_Engine_Systems.size(); i++)
	{
		m_Engine_Systems[i]->UpdateComponents();
	}


}



World::~World()
{
	for (int i = 0; i < m_Game_Systems.size(); i++)
	{
		m_Game_Systems[i]->Clear();
	}

	for (int i = 0; i < m_Engine_Systems.size(); i++)
	{
		m_Engine_Systems[i]->Clear();
	}

	for (int i = 0; i < m_Entitys.size(); i++)
	{
		delete(m_Entitys[i]);
	}

	for (int i = 0; i < m_Components.size(); i++)
	{
		m_Components[i].Clear(BaseComponent::getTypeSize(i));
	}
}
