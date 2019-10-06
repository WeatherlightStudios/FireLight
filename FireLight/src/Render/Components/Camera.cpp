#include "Camera.h"
#include "../../Core/GameObject.h"


Camera::Camera(Camera_Type type, float fov, float near, float far) : m_type(type), m_Fov(fov), m_Near(near), m_Far(far)
{
	MessageBus::SendMessage("CAMERA_REGISTER", { "CAMERA_REGISTER", this });
}


void Camera::Update()
{
	auto transform = GetOwner()->GetComponent<Transform>();
	glm::mat4 projection;
	if(m_type == Camera_Type::PERSPECTIVE)
		projection = glm::perspective(glm::radians(m_Fov), (float)FL::Window::getWidth() / (float)FL::Window::getHeight(), m_Near, m_Far);
	if(m_type == Camera_Type::ORTHOGRAPHIC)
		projection = glm::ortho(-(float)FL::Window::getWidth() / 2.0f, (float)FL::Window::getWidth() / 2.0f, -(float)FL::Window::getHeight() / 2.0f, (float)FL::Window::getHeight() / 2.0f, m_Near, m_Far);

	glm::mat4 yaw = glm::mat4(1.0f);
	glm::mat4 pitch = glm::mat4(1.0f);
	glm::mat4 roll = glm::mat4(1.0f);

	pitch = glm::rotate(pitch, glm::radians(transform->GetRotation().x), glm::vec3(1, 0, 0));
	yaw = glm::rotate(yaw, glm::radians(transform->GetRotation().y), glm::vec3(0, 1, 0));
	roll = glm::rotate(roll, glm::radians(transform->GetRotation().z), glm::vec3(0, 0, 1));

	glm::mat4 rotation = roll * pitch * yaw;
	glm::mat4 position = glm::mat4(1.0f);
	position = glm::translate(position, transform->GetPosition());

	glm::mat4 view = rotation * position;

	projection *= view;


	forward = glm::normalize(glm::vec3(view[0][2], view[1][2], view[2][2]));
	left = glm::normalize(glm::vec3(view[0][0], view[1][0], view[2][0]));
	upward = glm::normalize(glm::vec3(view[0][1], view[1][1], view[2][1]));

	m_projection = projection;
}

Camera::~Camera()
{
}
