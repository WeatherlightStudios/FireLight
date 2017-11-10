#include "TestScene.h"



TestScene::TestScene()
{
	m_rend = new Renderable;
}

void TestScene::Init()
{

	x = 12;
	y = 8;

	xx = 0;
	yy = 0;
	//gl3wInit();
	//ResourceManager::LoadTexture("sprite.png", true, "sprite");
	glClearColor(1, 0, 0, 1);
	ResourceManager::LoadTexture("sprite.png", true, "sprite");
	m_rend->set_texture("sprite");
	m_rend->set_texture_row(glm::vec2(x, y));
	addObject(m_rend);
}
void TestScene::Update(double dt)
{
	m_rend->set_texture_offset(glm::vec2(xx,yy));
	if (Window::isKeyDown(GLFW_KEY_W))
	{
		xx++;
	}

	if (Window::isKeyDown(GLFW_KEY_E))
	{
		yy++;
	}
}
void TestScene::Close()
{

}

TestScene::~TestScene()
{
}
