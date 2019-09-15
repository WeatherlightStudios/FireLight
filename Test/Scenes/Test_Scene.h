#ifndef TEST_SCENE_HEADER
#define TEST_SCENE_HEADER

#include <FireLight.h>
#include <memory>

//#include "../Component/TestComponent.h"


class Test_Scene : public Scene
{
public:


	Test_Scene();

	void Init();
	void Update();

	void Debug();

	void Close();

	~Test_Scene();


private:

};

#endif
