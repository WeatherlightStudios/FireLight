#pragma once
#include <FireLight.h>
#include "../Components/Grid.h"

SYSTEM(Grid_S)
{
public:
	Grid_S();
	void Update(uint32_t entity);
	~Grid_S();
private:

};