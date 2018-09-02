#include"World.h"

World::World()
{

}


EntityHandler* World::CreateEntity()
{
	Entity* newEntity = new Entity();
	EntityHandler* Handler = (EntityHandler*)newEntity;
	Handler->m_world = this;

	newEntity->first = m_Entitys.size();
	m_Entitys.push_back(newEntity);

	return Handler;
}

void World::removeEntity(EntityHandler* handler)
{
	Entity* entity = HandleToRow(handler);
	for (uint32_t i = 0; i < HandleToRow(handler)->second.size(); i++)
	{
		m_components[HandleToRow(handler)->second[i].first].erase(m_components[HandleToRow(handler)->second[i].first].begin() + HandleToRow(handler)->second[i].second);
		HandleToRow(handler)->second.erase(HandleToRow(handler)->second.begin() + i);
	}
	m_Entitys.erase(m_Entitys.begin() + entity->first);
	delete(entity);
}


void World::UpdateGameSystems()
{
	for (uint32_t i = 0; i < m_Game_Systems.size(); i++)
	{
		m_Game_Systems[i]->updateEntity();
	}
}


void World::addGameSystem(System* system)
{
	system->setWorld(this);
	system->Init();
	m_Game_Systems.push_back(system);
}
 

BaseComponent* World::getComponentByID(uint32_t ID, EntityHandler* handler)
{
	for (uint32_t i = 0; i < HandleToRow(handler)->second.size(); i++)
	{
		if (ID == HandleToRow(handler)->second[i].first)
		{
			return m_components[ID][HandleToRow(handler)->second[i].second];
		}
	}
}



World::~World()
{

}




//System Implementation
System::System()
{
}

void System::setWorld(World* world)
{
	m_world = world;
}

void System::updateEntity()
{

	for (int i = 0; i <  m_Entity.size(); i++)
	{
		std::vector<BaseComponent*> m_component;
		for (int x = 0; x < componentTypes.size(); x++)
		{
			m_component.push_back((BaseComponent*)m_world->getComponentByID(componentTypes[x], m_Entity[i]));
		}
		updateComponents(m_component);
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




//for Test

void TestSystem::Init()
{
	registerComponent<Transform>();
}

void TestSystem::updateComponents(std::vector<BaseComponent*> components)
{
	Transform* transform = (Transform*)components[0];

	transform->Position += 1;
}