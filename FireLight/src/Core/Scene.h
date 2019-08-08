#ifndef SCENE_H
#define SCENE_H

#include "SceneNode.h"

#include <vector>
#include <string>

using namespace std;

#define SCENE(T) class T : public Scene

class Scene
{
public:
	Scene();
	~Scene();

	/*-----------------------------------------Funzioni DEL ENGINE-----------------------------------*/
	void InitScene();
	void UpdateScene();
	void Render();
	void CloseScene();
	/*-----------------------------------------FUNZIONI DI GAMELOGIC-----------------------------------*/
	/*
	funzioni base della scena 
	devono essere inizializzate dalla classe che eredita "Scene" per poter essere utilizzate
	*/

	//e una funzione che viene richiamata all'inizzio quando la scena viene inizializzata
	//di solito si usa per inizializzare ogetti o caricare materiale nell resource manager
	//!piu avanti ci sara la possibilita di inizalizzare da file quindi bastare passare al costruttore della scena il percorso di quest'ultimo!
	virtual void Init(){}
	//funzione che viene richiamata ogni frame 
	virtual void Update(){}
	//funzione che viene richiamata ogni frame con l'ogetto debug che contiene funzioni di disegno e di UI adatti per il debugging (non funziona)
	virtual void Debug(){}

	//funzione richiamata alla chiusura di una scena solitamente accade quando si cambia scena o quando il gioco si chiude
	virtual void Close(){}
	
private:
	bool isInizialized;
	//SimpleRenderSystem m_render_system;


};

#endif