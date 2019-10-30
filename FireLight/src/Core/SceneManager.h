#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <string>
#include <map>
#include <memory>
#include "Scene.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static void AddScene(std::unique_ptr<FL::Scene> scene, std::string name);

	static void setCurrentScene(std::string name);

	static void InitCurrentScene();
	static void UpdateCurrentScene();
	static void DebugCurrentScene();
	static void DrawCurrentScene();
	static void CloseCurrentScene();

	static void changeCurrentSceneTo(std::string name);


private:

	static FL::Scene* m_current_scene;
	static std::map<std::string, std::unique_ptr<FL::Scene>> m_scenes;


};
#endif
