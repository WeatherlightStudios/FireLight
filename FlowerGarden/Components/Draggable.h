#pragma once

#include <FireLight.h>
#include <string>

COMPONENT(Draggable)
{
public:
	Draggable(string name): name(name){ }

	bool isPicked = false;
	string name = "";
};