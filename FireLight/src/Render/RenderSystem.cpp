#include "RenderSystem.h"

RenderSystem::RenderSystem()
{
	/*MessageBus::RegisterSystem("REGISTER_MESH", this);
	MessageBus::RegisterSystem("DEREGISTER_MESH", this);*/
}


void RenderSystem::Init()
{
	ResourceManager::LoadShader("Resources/ShaderTest.glsl", "ShaderTest");
	//ResourceManager::LoadShader("Resources/ShaderTest.vert", "Resources/ShaderTest.frag", nullptr, "ShaderTest");

	//Resource::LoadShader("Resources/ShaderTest.vert", "Resources/ShaderTest.frag", nullptr, "ShaderTest");


	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.f,
		 0.0f, 0.5f, 0.f
	};

	int index[] = 
	{
		0,1,2
	};

	FL::BufferLayout layout({
		{FL::DataType::Vec3}
	});

	m_vbo = std::make_shared<FL::VertexBuffer>();
	m_vao = std::make_shared<FL::VertexArray>();
	m_ibo = std::make_shared<FL::IndexBuffer>();

	m_vbo->BuilBuffer(sizeof(vertices), vertices, GL_STATIC_DRAW);
	m_vbo->SetBufferLayout(layout);


	m_vao->AddVertexBuffer(m_vbo);
}

void RenderSystem::Debug()
{

}

void  RenderSystem::Render()
{
	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, glm::vec3(0, 0, 0));
	model = glm::scale(model, glm::vec3(1, 1, 1));


	auto shader = ResourceManager::GetShader("ShaderTest");

	shader->SetMatrix4("projection", CameraSystem::GetCurrentCamera());
	shader->SetMatrix4("model", model);


	shader->Use();
	m_vao->Bind();

	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void RenderSystem::HandleMessage(Message msg)
{
	/*if (msg.type() == "REGISTER_MESH")
	{
		FL::LOG_INFO_ENGINE("Mesh is added");
		meshes.push_back((Mesh*)msg.getComponent());
	}

	if (msg.type() == "REMOVE_MESH")
	{
		//need implementation!
	}*/
}

RenderSystem::~RenderSystem()
{

}