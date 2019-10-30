#include "SceneManager.h"


std::map<std::string, std::unique_ptr<FL::Scene>>	SceneManager::m_scenes;
FL::Scene* SceneManager::m_current_scene;

SceneManager::SceneManager()
{
}

void SceneManager::AddScene(std::unique_ptr<FL::Scene> scene, std::string name)
{
	m_scenes[name] = std::move(scene);
}

void SceneManager::setCurrentScene(std::string name)
{
	m_current_scene = m_scenes[name].get();
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


void SceneManager::DebugCurrentScene()
{
	if (m_current_scene != nullptr)
	{
		m_current_scene->Debug();
		m_current_scene->DebugObjects();
	}
}

void SceneManager::CloseCurrentScene()
{
	if (m_current_scene != nullptr)
		m_current_scene->Close();
}


void SceneManager::DrawCurrentScene()
{
	if (m_current_scene != nullptr)
		m_current_scene->Render();
}

void SceneManager::changeCurrentSceneTo(std::string name)
{
	SceneManager::CloseCurrentScene();
	m_current_scene = m_scenes[name].get();
	SceneManager::InitCurrentScene();
}

SceneManager::~SceneManager()
{
}
