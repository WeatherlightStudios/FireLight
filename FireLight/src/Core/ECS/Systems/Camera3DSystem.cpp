#include "Camera3DSystem.h"



Camera3DSystem::Camera3DSystem()
{
	registerComponent(Transform::ID);
	registerComponent(Camera3D::ID);
}


void Camera3DSystem::Update(uint32_t entity)
{
	Transform* transform = World::getComponent<Transform>(entity);
	Camera3D* camera3D = World::getComponent<Camera3D>(entity);

	glm::mat4 projection = glm::perspective(glm::radians(camera3D->m_fov), (float)FL::Window::getWidth() / (float)FL::Window::getHeight(), camera3D->planeDist[0], camera3D->planeDist[1]);

	glm::mat4 yaw = glm::mat4(1.0f);
	glm::mat4 pitch = glm::mat4(1.0f);
	glm::mat4 roll = glm::mat4(1.0f);

	pitch = glm::rotate(pitch, glm::radians(transform->Rotation.x), glm::vec3(1, 0, 0));
	yaw = glm::rotate(yaw, glm::radians(transform->Rotation.y), glm::vec3(0, 1, 0));
	roll = glm::rotate(roll, glm::radians(transform->Rotation.z), glm::vec3(0, 0, 1));

	glm::mat4 rotation = roll * pitch * yaw;
	glm::mat4 position = glm::mat4(1.0f);
	position = glm::translate(position, transform->Position);

	glm::mat4 view = rotation * position;


	//glm::mat4 invert = glm::inverse(view);

	camera3D->forward = glm::normalize(glm::vec3(view[0][2], view[1][2], view[2][2]));
	camera3D->left = glm::normalize(glm::vec3(view[0][0], view[1][0], view[2][0]));
	camera3D->upward = glm::normalize(glm::vec3(view[0][1], view[1][1], view[2][1]));

	projection *= view;

	RenderManager::setProjection(projection);
	

}

Camera3DSystem::~Camera3DSystem()
{
}
