#ifndef TEST_SCENE_HEADER
#define TEST_SCENE_HEADER

#include <FireLight.h>
#include <memory>

#include "../Component/TestComponent.h"
#include "../Component/TerrainComponent.h"
#include "../Component/Box.h"
#include "../Component/Chunk.h"
#include "../Component/Moviment.h"

class Test_Scene : public FL::Scene
{
public:
	void Init();
	void Update();
	void Debug();
	void Close();

private:


};

#endif
