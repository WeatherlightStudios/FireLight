#ifndef APP_HEADER
#define APP_HEADER

#include <GL\gl3w.h>
#include <string>
#include <vector>
#include "Window.h"
#include "ECS\World.h"
#include "ECS\Components\Camera2D.h"
#include "ECS\Components\Sprite.h"
#include "ECS\Components\Transfrom.h"
#include "ECS\Components\MeshRender.h"
#include "ECS\Components\PhysicsBody.h"
#include "ECS\Systems\PysixSystem.h"
#include <GLFW\glfw3.h>
#include <Box2D\Box2D.h>

/*
App e la classe Core dell engine serve per l'inizializzazione delle scene e dell gioco in se.
Per poter utilizzare l'engine serve creare una classe e che derivi da App con unica funzione virtuale Init();
*/


//TEST
#define MS_PER_UPDATE 1 / 60.0


class App
{
public:
	App();
	virtual ~App();

	//funzione che inizializza tutti i sistemi dell engine 
	void Start();


	//setUp
	//TODO: creare solo una singola funzione che carica i settaggi da file


	/*Callbaks di GLFW*/
	void set_window_dimension(int width, int height);
	void set_windiw_name(std::string name);
protected:


	//il GameLoop principale dell engine
	void MainLoop();


	/*
	*queasta funzione ha lo scopo di inizizalizzare le scene create dall utente o per attivare funzioni di debug dell engine.
	*la funzione deve essere inizializzata dopo aver ereditato App per poterla utilizzare.
	*/
	virtual void Init() = 0;



	//Qui runna il codice di rendering viene richiamato dopo Update all'interno dell mainLoop
	void Render();

	//qui vengono richiamate tutte le funzioni di chiusura dei vari sistemi e viene liberata la memoria
	void ShutDown();


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