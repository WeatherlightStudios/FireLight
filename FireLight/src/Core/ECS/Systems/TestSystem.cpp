#include "TestSystem.h"



TestSystem::TestSystem()
{
	registerComponent(Test::ID);
}


void TestSystem::Update(uint32_t entity)
{
	Test* comp = World::getComponent<Test>(entity);

	comp->v += 10;
	
	//std::cout << comp->v << std::endl;

}


TestSystem::~TestSystem()
{
}
