#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <GL/gl3w.h>

#include "../Core/Window.h"
#include "../Utility/Resource.h"

#include "../Core/Time.h"

#include "../Core/ECS/Systems/Camera3DSystem.h"
#include "../Core/ECS/World.h"

class RenderManager
{
public:
	RenderManager();

	void Init();

	void Debug();

	//

	void Draw();

	void Close();



	static void setProjection(glm::mat4 projection) { m_projection = projection; }

	~RenderManager();


private:

	GLuint VAO, VBO;

	static glm::mat4 m_projection;
	glm::mat4 model;



};


#endif
