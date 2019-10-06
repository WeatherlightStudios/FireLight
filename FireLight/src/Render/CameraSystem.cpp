#include "CameraSystem.h"

Camera* CameraSystem::m_CurrentCamera;
std::vector<Camera*> CameraSystem::m_Cameras;

CameraSystem::CameraSystem()
{
}

void CameraSystem::Init()
{
	MessageBus::RegisterSystem("CAMERA_REGISTER", this);
	MessageBus::RegisterSystem("CAMERA_DEREGISTER", this);
}

void CameraSystem::RegisterCamera(Camera* camera)
{
	FL::LOG_INFO_ENGINE("Camera is Added");
	//if (m_CurrentCamera == nullptr)
		m_CurrentCamera = camera;
	m_Cameras.push_back(camera);
}

void CameraSystem::ChangeTo(Camera* camera)
{
	auto cam = std::find(m_Cameras.begin(), m_Cameras.end(), camera);
	int index = std::distance(m_Cameras.begin(), cam);
	m_CurrentCamera = m_Cameras[index];
}

glm::mat4 CameraSystem::GetCurrentCamera()
{
	return m_CurrentCamera->GetProjection();
}

void CameraSystem::HandleMessage(Message msg)
{
	if (msg.type() == "CAMERA_REGISTER")
	{
		RegisterCamera((Camera*)msg.getComponent());
	}

}



CameraSystem::~CameraSystem()
{
}
