#include "CameraSystem.h"

Camera* CameraSystem::m_CurrentCamera;
std::vector<Camera*> CameraSystem::m_Cameras;

CameraSystem::CameraSystem()
{
}

void CameraSystem::RegisterCamera(Camera* camera)
{
	if (m_CurrentCamera == nullptr)
		m_CurrentCamera = camera;
	m_Cameras.push_back(camera);
}

void CameraSystem::ChangeTo(Camera* camera)
{
	auto camera = std::find(m_Cameras.begin(), m_Cameras.end(), camera);
	m_CurrentCamera = camera;
}

glm::mat4 CameraSystem::GetCurrentCamera()
{
	return m_CurrentCamera->GetProjection();
}



CameraSystem::~CameraSystem()
{
}
