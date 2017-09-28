#ifndef APP_HEADER
#define APP_HEADER

#include <GL\gl3w.h>
#include <string>
#include <vector>
#include "Window.h"
#include "Renderable.h"
#include <GLFW\glfw3.h>

//test
#include "Camera.h"
namespace FL
{

	class App
	{
	public:
		App(const std::string name, int Width, int Height);
		virtual ~App();

		//Init Engine
		void start();
		//the game LOOP
		void mainLoop();
		//inizialize a Game
		virtual void Init() = 0;

		//---Like Unity system---
		//Update a GameLogic
		virtual void Update(double deltaT) = 0;
		//game render
		virtual void Draw() = 0;
		//close game
		virtual void Close() = 0;

		//RenderStuff
		void render();
		//free memory and close Engine
		void shutDown();

	private:

		bool		m_isRunning;
		double		m_oldTime;
		double		m_deltaLag;

		int			m_width;
		int			m_height;

		double lag;


		std::string		m_title;
		Window			*m_window;

		Renderable m_rend;
		//Camera m_camera;
	};

}

#endif