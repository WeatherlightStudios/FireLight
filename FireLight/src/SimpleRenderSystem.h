#ifndef SIMPLERENDERSYSTEM_H
#define SIMPLERENDERSYSTEM_H
//prototype

#include <vector>
#include "Renderable.h"
#include "Camera.h"



namespace FL
{
	namespace Graphic
	{

		 class SimpleRenderSystem
		{
		public:
			SimpleRenderSystem();

			void Add();
			void Render();

			void set_Camera(Camera *camera);

			~SimpleRenderSystem();
		private:
			 Camera* m_camera;

			 std::vector<Renderable*> m_renderables;

		};

	}
}
#endif SIMPLERENDERSYSTEM_H