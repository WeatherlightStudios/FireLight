#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
public:
	Component();

	virtual void Init();
	virtual void Update();

	~Component();

private:

	//TODO:: serve implementazione
	bool isActive;

};

#endif // !COMPONENT_H
