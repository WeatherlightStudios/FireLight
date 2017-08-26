#include "Camera.h"



Camera::Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = -90.f, float pitch = 0.f)
{
	m_Position = position;
	m_WorldUp = up;
	m_Yaw = yaw;
	m_Pitch = pitch;
	Update();
}


void Camera::Update()
{
	glm::vec3 front;

	front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
	front.y = sin(glm::radians(m_Pitch));
	front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

	m_Front = glm::normalize(front);

	m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp));
	m_Up = glm::normalize(glm::cross(m_Right, m_Front));
}

void Camera::Translate(glm::vec3 transform)
{
	m_Position += transform;
}

glm::vec3 Camera::get_VectorForward()
{
	return m_Front;
}
glm::vec3 Camera::get_VectorRight()
{
	return m_Right;
}


void Camera::Rotate(float Yaw, float Pitch)
{
	m_Yaw += Yaw;
	m_Pitch += Pitch;
}

glm::mat4 Camera::get_ViewMatrix()
{
	return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
}

glm::mat4 Camera::getCameraProjection()
{
	return glm::perspective(glm::radians(45.f), 800.f / 600.f, 0.1f, 10000.f);
}

Camera::~Camera()
{

}
