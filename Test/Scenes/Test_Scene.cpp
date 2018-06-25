#include "Test_Scene.h"
#include <math.h>
#include <GLFW\glfw3.h>
#include <iostream>

using namespace std;


Test_Scene::Test_Scene()
{

	m_cube = new Cube();

}



void Test_Scene::Init()
{
	ResourceManager::LoadTexture("source/Texture/tilea2.png", true, "tile1");
	ResourceManager::LoadTexture("source/Texture/tilea2.png", true, "sprite");

	ResourceManager::LoadShader("source/Shaders/2D_shader.vert", "source/Shaders/2D_shader.frag", NULL, "2D_shader");
	ResourceManager::LoadShader("source/Shaders/shader.vert", "source/Shaders/shader.frag", NULL, "shader");

	m_sprite = new Sprite();

	m_sprite->set_local_position(glm::vec3(0, 0, 0));

	m_sprite->set_local_scale(glm::vec3(1, 1, 1));
	m_sprite->set_local_rotation(0);

	add_object(*m_sprite);


	/*m_cube = new Cube();

	m_cube->set_local_position(glm::vec3(0, 0, 0));

	m_cube->set_local_scale(glm::vec3(1, 1, 1));
	m_cube->set_local_rotation(0);

	add_object(*m_cube);*/

	posX = 0;
	posY = 0;
	posZ = +3;

}


void Test_Scene::CameraUpdate(Camera *camera)
{
	speed = 4.5 * Time::GetDeltaTime();
	if (Window::isKeyDown(GLFW_KEY_W))
	{
		camPos += camera->get_front() * speed;
	}

	if (Window::isKeyDown(GLFW_KEY_S))
	{
		camPos -= camera->get_front() * speed;
	}

	if (Window::isKeyDown(GLFW_KEY_D))
	{
		camPos += glm::normalize(glm::cross(camera->get_front(), camera->get_up())) * speed;
	}

	if (Window::isKeyDown(GLFW_KEY_A))
	{
		camPos -= glm::normalize(glm::cross(camera->get_front(), camera->get_up())) * speed;
	}

	if (Window::isKeyDown(GLFW_KEY_SPACE))
	{
		posY += speed;
	}

	if (Window::isKeyDown(GLFW_KEY_LEFT_SHIFT))
	{
		posY -= speed;
	}


	Window::get_mouse_positions(xpos, ypos);


	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f; // change this value to your liking
	xoffset *= sensitivity;
	yoffset *= sensitivity;


	camera->set_transform(glm::vec3(camPos.x, posY, camPos.z));
	camera->rotate(xoffset, yoffset);

}

void Test_Scene::Update(double dt)
{

}

void Test_Scene::Debughing(Debug *debug)
{

}

void Test_Scene::Close()
{

}


Test_Scene::~Test_Scene()
{

}
