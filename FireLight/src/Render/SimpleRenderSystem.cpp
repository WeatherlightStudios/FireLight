#include "SimpleRenderSystem.h"

//Camera* SimpleRenderSystem::m_camera;


SimpleRenderSystem::SimpleRenderSystem()
{

}



void SimpleRenderSystem::Init()
{
	registerComponent<Transform>();
	registerComponent<Sprite>();
}


void SimpleRenderSystem::Update(std::vector<BaseComponent*> components)
{

}

void SimpleRenderSystem::Render(std::vector<BaseComponent*> components)
{

}



SimpleRenderSystem::~SimpleRenderSystem()
{
}