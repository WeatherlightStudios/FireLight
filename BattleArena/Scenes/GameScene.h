#ifndef GAMESCENE_HEADER
#define GAMESCENE_HEADER

#include <FireLight.h>
#include <Box2D/Box2D.h>

#include "../Systems/FPSCamera.h"


SCENE(GameScene)
{


public:

	GameScene();

	void Init();

	void Update();

	void Debug();

	void Close();


	~GameScene();

private:

	EntityHandler* camera;
	EntityHandler* testEntity;

	glm::vec3 projectOnPlane(glm::vec3 point, glm::vec3 norm);
	float angleBetween(glm::vec2 A, glm::vec2 B);
	glm::vec2 polarToEuclidian(float length, float angle);
	void AxisGizmo(Camera3D* cam);
	void CamGizmo(Camera3D* cam);

	bool isAxisGizmoEnabled = false;
	bool isCamGizmoEnabled = false;
};

#endif