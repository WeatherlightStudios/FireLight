#ifndef APP_HEADER
#define APP_HEADER

#include <GL\gl3w.h>
#include <string>
#include <vector>
#include "Window.h"
#include "../Render/Renderable.h"
#include <GLFW\glfw3.h>


#define MS_PER_UPDATE 1 / 60.0

/** 

*/


class App
{
public:
	App(const std::string name, int Width, int Height);
	virtual ~App();

		
	void start();

	void mainLoop();

	virtual void Init() = 0;


	void render();
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
};


#endif