#include "RenderSystem.h"

RenderSystem::RenderSystem()
{
	MessageBus::RegisterSystem("REGISTER_MESH", this);
	MessageBus::RegisterSystem("DEREGISTER_MESH", this);
}


void RenderSystem::Init()
{
	//glGenVertexArrays(1, &VAO);
 //   glGenBuffers(1, &VBO);

 //   glBindVertexArray(VAO);

 //   glBindBuffer(GL_ARRAY_BUFFER, VBO);
 //   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

 //   // position attribute
 //   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
 //   glEnableVertexAttribArray(0);
 //   // texture coord attribute
 //   glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
 //   glEnableVertexAttribArray(1);


	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);
}

void RenderSystem::Debug()
{

}




void  RenderSystem::Render()
{
	//glm::mat4 model;
	//model = glm::mat4(1.0f);
	//glm::mat4 view = glm::mat4(1.0f);
	//view = glm::translate(view, glm::vec3(0,0,-10));


	//model = glm::translate(model, glm::vec3(0, 0, 0));
	////model = glm::rotate(model, 1.0f, glm::vec3(1, 0, 0));

	//auto shader = Resource::getShader("terrain_shader");
	//auto texture = Resource::getTexture("TestBox");

	//m_projection = CameraSystem::GetCurrentCamera();

	//texture.Bind();
	//shader.Use();
	//shader.SetInteger("textures", 1);
	//shader.SetMatrix4("projection", m_projection);
	//shader.SetMatrix4("view", view);
	//shader.SetMatrix4("model", model);

	//glBindVertexArray(VAO);
	//glDrawArrays(GL_TRIANGLES, 0, 36);

	//model = glm::mat4(1.0f);
	//model = glm::translate(model, glm::vec3(0, -2, 0));
	//model = glm::scale(model, glm::vec3(10, 0.5, 10));
	//shader.Use();
	//shader.SetMatrix4("projection", m_projection);
	//shader.SetMatrix4("view", view);
	//shader.SetMatrix4("model", model);

	//glDrawArrays(GL_TRIANGLES, 0, 36);
	//glBindVertexArray(0);


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
}

RenderSystem::~RenderSystem()
{

}