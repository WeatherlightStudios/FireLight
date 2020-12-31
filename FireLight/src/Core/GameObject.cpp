#include "GameObject.h"
#include "Scene.h"


GameObject::GameObject()
{
	//this->AddComponent(std::make_shared<Transform>());
}

void GameObject::InitGameObject()
{
	Init();
}

void GameObject::UpdateGameObject()
{
	UpdateComponents();
	Update();
}

void GameObject::UpdateComponents()
{
	for (int i = 0; i < m_components.size(); i++)
	{
		m_components[i]->Update();
	}
}

void GameObject::DebugComponents()
{
	for (int i = 0; i < m_components.size(); i++)
	{
		m_components[i]->Debug();
	}
}

void GameObject::AddComponent(const std::shared_ptr<Component>& component)
{
	component->setGameObject(this);
	component->Init();
	m_components.push_back(std::move(component));
}

void GameObject::RemoveComponent(std::shared_ptr<Component> component)
{
	m_components.erase(std::remove(m_components.begin(), m_components.end(), component), m_components.end());
}

void GameObject::ClearComponents()
{
	m_components.clear();
}

void GameObject::AddChildren(std::shared_ptr<GameObject> children)
{
	children->SetParent(this);
	m_children.push_back(children);
	m_scene->SetParent(ID, children->GetID());
}

void GameObject::RemoveChildren(std::shared_ptr<GameObject> children)
{
	//TODO
	//Need to be tested
	m_children.erase(std::remove(m_children.begin(), m_children.end(), children), m_children.end());
}

GameObject::~GameObject()
{
}
