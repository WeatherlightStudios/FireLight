#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>

class GameObject;

class Component
{
public:
	Component();

	virtual void Init() {}
	virtual void Update() {}
	virtual void Debug() {}


	void setGameObject(GameObject* obj) { m_Owner = obj; }

	GameObject* GetOwner() { return m_Owner; }

	~Component();

protected:


	//TODO:: serve implementazione
	bool m_IsActive;

	GameObject* m_Owner;

};

#endif // !COMPONENT_H
