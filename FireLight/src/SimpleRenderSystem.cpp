#include "SimpleRenderSystem.h"

namespace FL
{
	namespace Graphic
	{
		SimpleRenderSystem::SimpleRenderSystem()
		{
		}


		void SimpleRenderSystem::Add()
		{
			//m_renderables = renderables;
		}

		void SimpleRenderSystem::Render()
		{
			for (int i = 0; i < m_renderables.size(); i++)
			{
				//m_renderables.at(i)->Render(*m_camera);
			}
		}

		void SimpleRenderSystem::set_Camera(Camera *camera)
		{
			m_camera = camera;
		}


		SimpleRenderSystem::~SimpleRenderSystem()
		{
		}



	}

}