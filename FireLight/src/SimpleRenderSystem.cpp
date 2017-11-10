#include "SimpleRenderSystem.h"
#include <iostream>

Camera* SimpleRenderSystem::m_camera;

std::vector<Renderable*> SimpleRenderSystem::m_renderables;

SimpleRenderSystem::SimpleRenderSystem()
{

}


void SimpleRenderSystem::Add(Renderable *rend)
{
	//m_renderables = renderables;
	m_renderables.push_back(rend);
}
void SimpleRenderSystem::remove(Renderable *rend)
{
	m_renderables.erase(std::find(m_renderables.begin(), m_renderables.end(), rend));
}

void SimpleRenderSystem::Render()
{
	for (int i = 0; i < m_renderables.size(); i++)
	{
		m_renderables[i]->Render(*m_camera);
	}

	//std::cout << m_renderables.size() << std::endl;
}

void SimpleRenderSystem::set_Camera(Camera *camera)
{
	m_camera = camera;
}


SimpleRenderSystem::~SimpleRenderSystem()
{
}