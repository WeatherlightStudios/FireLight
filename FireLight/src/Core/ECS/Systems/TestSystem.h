#pragma once


#include "../System.h"
#include "../World.h"
#include "../Components/Test.h"

class TestSystem : public System
{
public:
	TestSystem();

	void Update(uint32_t entity);

	~TestSystem();
};

