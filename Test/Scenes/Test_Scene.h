#ifndef TEST_SCENE_HEADER
#define TEST_SCENE_HEADER

#include <FireLight.h>
#include <memory>




class Test_Scene : public Scene
{
public:


	Test_Scene();

	void Init();
	void CameraUpdate(Camera *camera);
	void Update();
	void Debughing(Debug *debug);
	void Close();

	~Test_Scene();


private:
	float t; 

	glm::vec3 camPos;

	float speed;

	float posX, posY, posZ;


	float lastX ,lastY;


	//camera Test
	double xpos, ypos;

	EntityHandler* entity;

	int i;
};

#endif
