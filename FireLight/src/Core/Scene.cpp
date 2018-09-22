#include "Scene.h"
#include <iostream>



Scene::Scene()
{
	isInizialized = false;
}


void Scene::init_scene()
{
	
	//m_render_system.Init();
	Init();
	isInizialized = true;
}
void Scene::update_scene()
{
	Update();
}

void Scene::render()
{
	//m_render_system.Update();
}

void Scene::close_scene()
{
	Close();
}

Scene::~Scene()
{
}
