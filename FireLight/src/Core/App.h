#ifndef APP_HEADER
#define APP_HEADER

#include <GL\gl3w.h>
#include <string>
#include <vector>
#include "Window.h"
#include "../Render/Renderable.h"
#include <GLFW\glfw3.h>

#include "ECS\World.h"


//TEST
#define MS_PER_UPDATE 1 / 60.0

/**
	La classe App viene utilizzata per inizializzare l'engine e il gioco.
	Tramite la funzione virtuale Init e possibile inizializzare le risorse del gioco

*/
class App
{
public:
	App();
	virtual ~App();

		
	void start();

	void mainLoop();



	virtual void Init() = 0;


	void render();


	void shutDown();


	//setUp
	//TODO: creare solo una singola funzione che carica i settaggi da file
	void set_window_dimension(int width, int height);
	void set_windiw_name(std::string name);


private:

	bool		m_isRunning;
	double		m_oldTime;
	double		m_deltaLag;

	int			m_width;
	int			m_height;

	World m_world;

	double lag;

	std::string		m_title;
	Window			*m_window;
};


#endif