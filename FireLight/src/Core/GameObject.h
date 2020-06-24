#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>
#include <typeinfo> 

#include "Component.h"

#include "../Utility/Debugging/Log.h"

namespace FL
{

	class Scene;

}

class GameObject
{
public:
	GameObject();
	//Camera
	//Sprite

public:


	virtual void Init() {}
	virtual void Update() {}
	virtual void Debug() {}


	void InitGameObject();
	void UpdateGameObject();

	void UpdateComponents();
	void DebugComponents();

	void AddComponent(const std::shared_ptr<Component>& component);
	void RemoveComponent(std::shared_ptr<Component> component);

	template<class T>
	T* GetComponent()
	{
		for (auto& e : m_components)
		{
			if (dynamic_cast<T*>(e.get()) != nullptr)
			{
				return (T*)e.get();
			}
		}

		return nullptr;
	}

	void SetID(uint32_t id) { ID = id; }
	uint32_t GetID() { return ID; }

	void SetScene(FL::Scene* scene) { m_scene = scene; }
	FL::Scene* getScene() { return m_scene; }
	//nel caso serva verra implementato
	//void GetComponent();
	//void GetComponents();

	void AddChildren(std::weak_ptr<GameObject> children);
	void RemoveChildren(std::weak_ptr<GameObject> children);


	void SetParent(GameObject* parent)
	{
		m_parent = parent;
	}



	~GameObject();


private:
	FL::Scene* m_scene;

	GameObject* m_parent;

	std::vector<std::weak_ptr<GameObject>> m_children;
	std::vector<std::shared_ptr<Component>> m_components;




	uint32_t ID;


};

#endif