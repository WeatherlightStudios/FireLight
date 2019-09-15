#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
	Component();

	virtual void Init() {}
	virtual void Update() {}
	virtual void Debug() {}

	~Component();

private:

	//TODO:: serve implementazione
	bool isActive;

};

#endif // !COMPONENT_H
