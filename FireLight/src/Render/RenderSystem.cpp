#include "RenderSystem.h"

RenderSystem::RenderSystem()
{
	MessageBus::RegisterSystem("REGISTER_MESH", this);
	MessageBus::RegisterSystem("DEREGISTER_MESH", this);
}


void RenderSystem::Init()
{

}

void RenderSystem::Debug()
{

}





void  RenderSystem::Render()
{
	for (int i = 0; i < meshes.size(); i++)
	{
		meshes[i]->UpdateMesh();
		meshes[i]->Draw();
	}

}

void RenderSystem::HandleMessage(Message msg)
{
	if (msg.type() == "REGISTER_MESH")
	{
		FL::LOG_INFO_ENGINE("Mesh is added");
		meshes.push_back((Mesh*)msg.getComponent());
	}

	if (msg.type() == "REMOVE_MESH")
	{
		//need implementation!
	}
}

RenderSystem::~RenderSystem()
{

}