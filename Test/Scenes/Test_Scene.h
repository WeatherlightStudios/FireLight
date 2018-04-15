#ifndef TEST_SCENE_HEADER
#define TEST_SCENE_HEADER

#include <FireLight.h>




class Test_Scene : public Scene
{
public:


	Test_Scene();

	void Init();
	void CameraUpdate(Camera *camera);
	void Update(double dt);
	void Debughing(Debug *debug);
	void Close();

	~Test_Scene();


private:

	Renderable *m_sprite;
	float t; 



};

#endif
