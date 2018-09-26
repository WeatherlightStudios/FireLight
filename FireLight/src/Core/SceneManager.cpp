#include "SceneManager.h"


std::map<std::string, Scene*>	SceneManager::m_scenes;
Scene* SceneManager::m_current_scene;

SceneManager::SceneManager()
{
}

void SceneManager::AddScene(Scene* scene, std::string name)
{
	m_scenes[name] = scene;
}

void SceneManager::setCurrentScene(std::string name)
{
	m_current_scene = m_scenes[name];
	m_current_scene->InitScene();
}

void SceneManager::InitCurrentScene()
{
	if (m_current_scene != nullptr)
		m_current_scene->InitScene();
}
void SceneManager::UpdateCurrentScene()
{
	if (m_current_scene != nullptr)
		m_current_scene->UpdateScene();

}
void SceneManager::RenderCurrentScene()
{
	if (m_current_scene != nullptr)
		m_current_scene->Render();
}

void SceneManager::CloseCurrentScene()
{
	if (m_current_scene != nullptr)
		m_current_scene->Close();
}

void SceneManager::changeCurrentSceneTo(std::string name)
{
	SceneManager::CloseCurrentScene();
	m_current_scene = m_scenes[name];
	SceneManager::InitCurrentScene();
}

SceneManager::~SceneManager()
{
}
