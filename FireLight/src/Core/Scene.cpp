#include "Scene.h"
#include <iostream>



Scene::Scene()
{
	isInizialized = false;
}


void Scene::InitScene()
{
	
	Init();
	isInizialized = true;
}
void Scene::UpdateScene()
{
	Update();
}

void Scene::Render()
{

}

void Scene::CloseScene()
{
	Close();
}

Scene::~Scene()
{
}
