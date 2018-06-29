#ifndef CAMERA_HEADER
#define CAMERA_HEADER

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera2D
{
public:
	Camera2D();

	glm::mat4 getMatrix();


	static void rotate(float rotation_ammount);
	static void translate(glm::vec3 pos_ammount);

	static void set_position(glm::vec3 pos);
	static void set_rotation(float rotation);

	~Camera2D();

private:

	 glm::mat4 m_projection;

	static float m_rotation;

	static glm::vec3 m_position;
};


#endif
