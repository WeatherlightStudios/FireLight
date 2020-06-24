#ifndef SCENE_H
#define SCENE_H


#include <vector>
#include <string>

#include <memory>

#include "GameObject.h"

#include "../Render/Simple2DRenderSystem.h"
#include "../Render/RenderSystem.h"

#include "../Utility/ResourceManager.h"



#define SCENE(T) class T : public Scene

namespace FL
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		//Game Engine Functions
		//function that inizialize the scene
		void InitScene();
		//Function that update the GameLogic and the Engine systems
		void UpdateScene();
		//This function is used to update the render system end perform some logic
		void Render();
		//this function free the memory clear the systems and close all 
		void CloseScene();

		/*!###GameLogic Functions
		* This virtual functions is used for loading the resources and implement the game logic
		*/
		//This function is used for inizialize the Scene, Load the resources and inizialize the game objects
		virtual void Init(){}
		//Function that is called once per frame and is used for perform some logic on the entire scene
		virtual void Update(){}
		//Function that is called once per frame and is used for Debugging purpuse
		virtual void Debug(){}
		//This function is called when the scene is close
		virtual void Close(){}

		//Function that update the debug of the objects
		void DebugObjects()
		{
			for (auto& e : m_object)
			{
				e->Debug();
				e->DebugComponents();
			}
		}

		//SCENE GRAPH
		//This Function Instantiate a GameObject in the scene and returns it
		std::shared_ptr<GameObject> CreateGameOject();
		//Function that search and remove GameObject from the scene
		void RemoveGameObject(std::shared_ptr<GameObject>  object);
		//Search and return a GameObject by ID
		std::weak_ptr<GameObject> GetGameObject(uint32_t ID);
		//Set a GameObject parent
		void SetParent(uint32_t parentID , uint32_t childID);

		std::shared_ptr<ResourceManager> GetResourceManager() { return m_resource_manger; }

	protected:

		bool isInizialized;

	private:

		std::vector<std::shared_ptr<GameObject>> m_object;

		std::vector<std::weak_ptr<GameObject>> m_parents;

		std::unique_ptr<RenderSystem> m_render;

		std::shared_ptr<ResourceManager> m_resource_manger;

		CameraSystem* m_cameraSyste;
	};

}

#endif