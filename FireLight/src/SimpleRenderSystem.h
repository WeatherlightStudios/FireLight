#pragma once

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

			static void Add(const Renderable *renderable);
			static void Remove(const std::string name);
			static void Render();

			static Renderable* getRenderable(const std::string name);

			static void set_Camera(const Camera *camera);

			~SimpleRenderSystem();
		private:
			static std::vector<Renderable*> m_renderables;
			static Camera* m_camera;
		};

	}
}
