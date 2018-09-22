#include"World.h"

std::map<uint32_t, std::vector<BaseComponent*>> World::m_components;
std::vector<System*> World::m_Game_Systems;
std::vector<Entity*> World::m_Entitys;

World::World()
{

}


EntityHandler* World::CreateEntity()
{
	Entity* newEntity = new Entity();
	std::get<2>(*newEntity) = new std::bitset<1024>;
	EntityHandler* Handler = (EntityHandler*)newEntity;
	m_Entitys.push_back(newEntity);
	return Handler;
}

void World::removeEntity(EntityHandler* handler)
{
	Entity* entity = HandleToRow(handler);

	for (uint32_t i = 0; i < std::get<1>(*entity).size(); i++)
	{
		m_components[std::get<1>(*entity)[i].first].erase(m_components[std::get<1>(*entity)[i].first].begin() + std::get<1>(*entity)[i].second);
		std::get<1>(*entity).erase(std::get<1>(*entity).begin() + i);
	}

	m_Entitys.erase(m_Entitys.begin() + std::get<0>(*entity));
	delete(entity);
}

void World::UpdateGameSystems()
{
	for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
	{
		if (m_Game_Systems[i]->getSize() > 0)
		{
			m_Game_Systems[i]->updateEntity();
		}
	}
}

void World::InitGameSystems()
{
	for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
	{
		if (m_Game_Systems[i]->getSize() > 0)
		{
			m_Game_Systems[i]->InitAllEntity();
		}
	}
}


void World::RenderGameSystems()
{
	for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
	{
		if (m_Game_Systems[i]->getSize() > 0)
		{
			m_Game_Systems[i]->Draw();
		}
	}
}


void World::addGameSystem(System* system)
{
	system->Init();
	m_Game_Systems.push_back(system);
}
 

BaseComponent* World::getComponentByID(uint32_t ID, EntityHandler* handler)
{
	

	for (uint32_t i = 0; i < std::get<1>(*HandleToRow(handler)).size(); i++)
	{
		if (ID == std::get<1>(*HandleToRow(handler))[i].first)
		{
			return m_components[ID][std::get<1>(*HandleToRow(handler))[i].second];
		}
	}
}


void World::removeGameSystem(System* system)
{

}


World::~World()
{
	for (std::vector<System*>::iterator i = m_Game_Systems.begin(); i != m_Game_Systems.end(); ++i) {
		delete *i;
	}
	m_Game_Systems.clear();
	for (std::vector<Entity*>::iterator i = m_Entitys.begin(); i != m_Entitys.end(); ++i) {
		delete *i;
	}
	m_Entitys.clear();

	std::map<uint32_t, std::vector<BaseComponent*>>::iterator it;
	for (it = m_components.begin(); it != m_components.end(); it++)
	{
		for (std::vector<BaseComponent*>::iterator i = it->second.begin(); i != it->second.end(); ++i) {
			delete *i;
		}
	}
	m_components.clear();
}



//System Implementation
System::System()
{
	m_key = new std::bitset<1024>;
	this->m_key->reset();
}
void System::updateEntity()
{

	for (int i = 0; i <  m_Entity.size(); i++)
	{
		std::vector<BaseComponent*> m_component;
		for (int x = 0; x < componentTypes.size(); x++)
		{
			m_component.push_back(World::getComponentByID(componentTypes[x], m_Entity[i]));
		}
		Update(m_component);
		//Render(m_component);
	}
}


void System::InitAllEntity()
{
	for (int i = 0; i < m_Entity.size(); i++)
	{
		std::vector<BaseComponent*> m_component;
		for (int x = 0; x < componentTypes.size(); x++)
		{
			m_component.push_back(World::getComponentByID(componentTypes[x], m_Entity[i]));
		}
		InitEntity(m_component);
	}
}

void System::Draw()
{
	for (int i = 0; i < m_Entity.size(); i++)
	{
		std::vector<BaseComponent*> m_component;
		for (int x = 0; x < componentTypes.size(); x++)
		{
			m_component.push_back(World::getComponentByID(componentTypes[x], m_Entity[i]));
		}
		//Update(m_component);
		Render(m_component);
	}
}


void System::registerEntity(EntityHandler* entity)
{
	m_Entity.push_back(entity);
}

void System::deregisterEntity(EntityHandler* entity)
{
	m_Entity.erase(std::find(m_Entity.begin(), m_Entity.end(), entity));
}


System::~System()
{
}
//**********************************