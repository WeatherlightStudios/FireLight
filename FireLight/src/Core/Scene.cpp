#include "Scene.h"
#include <iostream>



Scene::Scene()
{
	isInizialized = false;
	m_render = std::make_unique<RenderSystem>();
}


void Scene::InitScene()
{
	Init();
	m_render->Init();
	isInizialized = true;
}
void Scene::UpdateScene()
{
	Update();

	for (int i = 0; i < m_object.size(); i++)
	{
		m_object[i]->UpdateGameObject();
	}
}

void Scene::Render()
{

	/*m_render->Begin();
	for (int i = 0; i < m_object.size(); i++)
	{
		Sprite* component = m_object[i]->GetComponent<Sprite>();
		Transform* trnasf = m_object[i]->GetComponent<Transform>();
		if (component != nullptr)
		{
			m_render->SubmitSprite(trnasf, component);
		}
	}
	m_render->End();

	
	m_render->Flush();
*/

	m_render->Render();
}

void Scene::CloseScene()
{
	Close();
}


//SCENE GRAPH

std::shared_ptr<GameObject> Scene::CreateGameOject()
{
	uint32_t size = m_object.size();
	m_object.push_back(std::make_shared<GameObject>());
	m_object.back()->SetID(size);
	m_object.back()->SetScene(this);
	m_parents.resize(m_object.size());
	return m_object.back();
}

void Scene::RemoveGameObject(std::shared_ptr<GameObject> ptr)
{
	//auto ptr = object.lock();

	if (ptr->GetID() != m_object.size() - 1)
	{
		uint32_t tempID = ptr->GetID();
		m_object.back()->SetID(tempID);
		m_object[tempID] = m_object.back();
		m_parents[tempID] = m_parents.back();
		m_object.pop_back();
		m_parents.pop_back();
	}
	else
	{
		m_object.pop_back();
		m_parents.pop_back();
	}

}


void Scene::SetParent(uint32_t parentID, uint32_t childID)
{
	m_parents[childID] = m_object[parentID];
}


Scene::~Scene()
{
}
