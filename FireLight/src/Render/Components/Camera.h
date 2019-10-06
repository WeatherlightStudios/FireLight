#ifndef CAMERA_H
#define CAMERA_H

#include "../../Core/Component.h" 
#include "Transform.h"

#include "../../Core/Window.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../../Core/MessageSystem/MessageBus.h"
#include "../../Core/MessageSystem/Message.h"

enum Camera_Type {
	PERSPECTIVE,
	ORTHOGRAPHIC
};


class Camera : public Component
{
public:
	Camera(Camera_Type type, float fov, float near, float far);

	void Update();

	glm::mat4 GetProjection() { return m_projection; }

	~Camera();

	glm::vec3 forward;
	glm::vec3 upward;
	glm::vec3 left;

private:

	glm::mat4 m_projection;
	Camera_Type m_type;
	float m_Fov;
	float m_Far;
	float m_Near;

};



#endif
