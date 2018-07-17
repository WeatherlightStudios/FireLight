#ifndef COMPONENT_HEADER
#define COMPONENT_HEADER

#include <memory>

struct BaseComponent
{
	static uint32_t getID();
	static uint32_t ID;
};

template<typename T>
struct Component : public BaseComponent
{
	static uint32_t unique_ID;
};

template<typename T>
uint32_t Component<T>::unique_ID(BaseComponent::getID());

//ForTest
template<typename T>
struct Transform : public Component<T>
{
	float x, y, z;
};
template<typename T>
struct Render : public Component<T>
{
	float x, y, z;
};




#endif // !COMPONENT_HEADER

