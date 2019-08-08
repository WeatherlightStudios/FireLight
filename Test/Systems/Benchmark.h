#pragma once

#include <FireLight.h>
#include "../Components/Movement.h"


class Benchmark : public System
{
public:
	Benchmark();

	void Update(uint32_t entity);

	~Benchmark();
};

