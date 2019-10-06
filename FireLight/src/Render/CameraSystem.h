#ifndef CAMERASYSTEM_H
#define CAMERASYSTEM_H

#include <vector>
#include "Components/Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../Core/MessageSystem/MessageBus.h"
#include "../Core/System.h"

#include "../Utility/Debugging/Log.h"

class CameraSystem : public System
{
public:
	CameraSystem();

	void Init();

	//void Debug();

	void HandleMessage(Message msg);

	static void RegisterCamera(Camera* camera);

	static void ChangeTo(Camera* cam);

	static glm::mat4 GetCurrentCamera();

	~CameraSystem();
private:
	static Camera* m_CurrentCamera;
	static std::vector<Camera*> m_Cameras;
};

#endif