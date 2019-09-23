#ifndef TEST_SCENE_HEADER
#define TEST_SCENE_HEADER

#include <FireLight.h>
#include <memory>

//#include "../Component/TestComponent.h"
class Test_Scene : public Scene
{
public:
	void Init();
	void Update();
	void Debug();
	void Close();

private:

};

#endif
