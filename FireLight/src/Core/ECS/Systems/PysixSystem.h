#ifndef PYSIXSYSTEM_H
#define PYSIXSYSTEM_H


#include "../World.h"
#include "../Components/PhysicsBody.h"
#include "../Components/Transfrom.h"


class PysixSystem : public System
{
public:
	PysixSystem();
	void Init();
	void Update(std::vector<BaseComponent*> components);

	~PysixSystem();
};


#endif PYSIXSYSTEM_H