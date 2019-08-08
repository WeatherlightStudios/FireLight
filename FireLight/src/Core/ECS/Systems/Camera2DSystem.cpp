#include "Camera2DSystem.h"



Camera2DSystem::Camera2DSystem()
{
	registerComponent(Transform::ID);
	registerComponent(Camera2D::ID);
}


void Camera2DSystem::Update(uint32_t entity)
{
	Transform* transform = World::getComponent<Transform>(entity);
	Camera2D* camera2D = World::getComponent<Camera2D>(entity);

	glm::mat4 projection = glm::ortho(-(float)FL::Window::getWidth() / 2.0f, (float)FL::Window::getWidth() / 2.0f, -(float)FL::Window::getHeight() / 2.0f, (float)FL::Window::getHeight() / 2.0f, 0.001f, 10000.0f);
	glm::mat4 orientation;

	orientation = glm::rotate(orientation, 0.0f, glm::vec3(1, 0, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 1, 0));
	orientation = glm::rotate(orientation ,0.0f, glm::vec3(0,0,1));

	projection *= orientation;
	projection = glm::translate(projection, glm::vec3(transform->Position.x, transform->Position.y, -3.0));

	camera2D->projection = projection;
}

Camera2DSystem::~Camera2DSystem()
{
}
