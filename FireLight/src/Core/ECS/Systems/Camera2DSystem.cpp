#include "Camera2DSystem.h"



Camera2DSystem::Camera2DSystem()
{
	registerComponent(Transform::ID);
	registerComponent(Camera2D::ID);
}


void Camera2DSystem::Update(BaseComponent** components)
{
	/*Transform* transform = (Transform*)components[0];
	Camera2D* camera2D = (Camera2D*)components[1];

	glm::mat4 projection = glm::ortho(-(float)Window::getWidth() / 2.0f, (float)Window::getWidth() / 2.0f, -(float)Window::getWidth() / 2.0f, (float)Window::getWidth() / 2.0f, 0.001f, 10000.0f);
	glm::mat4 orientation;

	orientation = glm::rotate(orientation, 0.0f, glm::vec3(1, 0, 0));
	orientation = glm::rotate(orientation, 0.0f, glm::vec3(0, 1, 0));
	orientation = glm::rotate(orientation ,0.0f, glm::vec3(0,0,1));

	projection *= orientation;
	projection = glm::translate(projection, glm::vec3(transform->Position.x, transform->Position.y, -3.0));*/
}

Camera2DSystem::~Camera2DSystem()
{
}
