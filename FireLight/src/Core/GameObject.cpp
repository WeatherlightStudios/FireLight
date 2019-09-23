#include "GameObject.h"
#include "Scene.h"


GameObject::GameObject()
{
	FL::LOG_INFO_ENGINE("ObjectIsCreated");
}

void GameObject::InitGameObject()
{
	Init();
	//InitComponents();
}
void GameObject::UpdateGameObject()
{
	Update();
	UpdateComponents();
}

void GameObject::UpdateComponents() 
{
	for (auto& e : m_components)
	{
		e->Update();
	}
}

void GameObject::DebugComponents()
{
	for (auto& e : m_components)
	{
		e->Debug();
	}
}

void GameObject::AddComponent(std::shared_ptr<Component> component)
{
	component->setGameObject(this);
	component->Init();
	m_components.push_back(std::move(component));
}
void GameObject::RemoveComponent(std::shared_ptr<Component> component)
{
	m_components.erase(std::remove(m_components.begin(), m_components.end(), component), m_components.end());
}



void GameObject::AddChildren(std::weak_ptr<GameObject> children)
{
	children.lock()->SetParent(this);
	m_children.push_back(children);
	m_scene->SetParent(ID, children.lock()->GetID());
}

void GameObject::RemoveChildren(std::weak_ptr<GameObject> children)
{
	//TODO
}


GameObject::~GameObject()
{
	FL::LOG_INFO_ENGINE("ObjectIsDestroyed");
}
