#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <string>
#include <map>
#include "Scene.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static void AddScene(Scene *scene, std::string name);

	static void setCurrentScene(std::string name);

	static void InitCurrentScene();
	static void UpdateCurrentScene();
	static void DebugCurrentScene();

	static void CloseCurrentScene();

	static void changeCurrentSceneTo(std::string name);


private:

	static Scene* m_current_scene;
	static std::map<std::string, Scene*> m_scenes;


};
#endif
