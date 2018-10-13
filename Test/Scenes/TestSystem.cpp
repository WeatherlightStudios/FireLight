#include "TestSystem.h"



TestSystem::TestSystem()
{
	registerComponent<Transform>();
}


void TestSystem::Update(std::vector<BaseComponent*> components)
{
	Transform* transf = (Transform*)components[0];

	transf->position.x += 5;
}

TestSystem::~TestSystem()
{
}
