#include "Component.h"


uint32_t BaseComponent::ID = 0;



uint32_t BaseComponent::getID()
{
	return ID++;
}