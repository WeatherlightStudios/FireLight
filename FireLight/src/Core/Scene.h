#ifndef SCENE_H
#define SCENE_H

#include "SceneNode.h"
#include "../Render/SimpleRenderSystem.h"
#include "../Utility/Debug.h"


#include <vector>
#include <string>

using namespace std;

class Scene
{
public:
	Scene();
	~Scene();

	/*-----------------------------------------Funzioni DELL ENGINE-----------------------------------*/
	void init_scene();
	void update_scene(double dt);
	void render();
	void close_scene();
	



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
	virtual void Debughing(Debug *debug){}
	//funzione richiamata alla chiusura di una scena solitamente accade quando si cambia scena o quando il gioco si chiude
	virtual void Close(){}

	/*-------------------------------------------FUNZIONI OBSOLETE-------------------------------------*/
	//TODO: Da riscrivere tutto il sistema di gerarchia
	void add_object(SceneNode &node);
	//void add_objectTo(SceneNode *parentNode, SceneNode *node);
	void remove_object(SceneNode &node);
	//void remove_objectFrom(SceneNode *parentNode, SceneNode *node);

	void update_objects(double dt);
	void add_renderable_node(SceneNode &node);
	void remove_renderable_node(SceneNode &node);

	SceneNode* get_object(string name);

private:
	bool isInizialized;

	Debug *m_debug;
	SimpleRenderSystem m_render_system;
	std::vector<SceneNode*> m_graph_objects;
	//Camera *m_camera;
	//Camera2D *m_camera2D;
};

#endif