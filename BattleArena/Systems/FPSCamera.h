#pragma once

#include <FireLight.h>

SYSTEM(FPSCamera)
{
public:
	FPSCamera();

	void Update(uint32_t entity);

	~FPSCamera();

private:
	bool isEnabled = false;
};

