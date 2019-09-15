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


	void setGameObject(GameObject* obj) { gameObject = obj; }

	~Component();

protected:

	//TODO:: serve implementazione
	bool isActive;

	GameObject* gameObject;

};

#endif // !COMPONENT_H
