#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <memory>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Component.h"

class Scene;


class GameObject
{
public:
	GameObject();

	virtual void Init() {}
	virtual void Update() {}

	void InitGameObject();
	void UpdateGameObject();

	void InitComponents();
	void UpdateComponents();

	void AddComponent(std::shared_ptr<Component> component);
	void RemoveComponent(std::shared_ptr<Component> component);


	void SetID(uint32_t id) { ID = id; }
	uint32_t GetID() { return ID; }

	void SetScene(Scene* scene) { m_scene = scene; }

	//nel caso serva verrai implementato
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
	Scene* m_scene;

	GameObject* m_parent;

	std::vector<std::weak_ptr<GameObject>> m_children;
	std::vector<std::shared_ptr<Component>> m_components;




	uint32_t ID;


};

#endif