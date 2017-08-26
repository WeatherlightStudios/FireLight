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

namespace fl
{
	class App
	{
	public:
		App(const std::string name, int Width, int Height);
		~App();


		//Init Engine
		void Start();

		//the game LOOP
		void MainLoop();

		//inizialize a Game
		void Init();
		//Update a GameLogic
		void Update(double deltaT);
		//RenderStuff
		void Render();
		//free memory and close
		void ShutDown();

	private:

		bool		m_isRunning;
		double		m_oldTime;
		double		m_deltaLag;

		int			m_width;
		int			m_height;


		double		m_mouseX, m_mouseY;
		float OldmouseX;
		float OldmouseY;
		const double	FRAME_LIMIT = 1.0 / 60.0;



		std::string		m_title;
		Window			*m_window;

		Renderable m_rend;
		Camera m_camera;
	};

}
#endif