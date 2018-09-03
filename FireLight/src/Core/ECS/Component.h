#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <glm\vec3.hpp>

struct BaseComponent
{
	static uint32_t registerComponentType();
private:
	static uint32_t index;
};

template<class T>
struct Component : public BaseComponent
{
	static const uint32_t ID;
};

template<class T>
const uint32_t Component<T>::ID(BaseComponent::registerComponentType());
#endif

