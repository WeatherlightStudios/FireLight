#ifndef TEST_SCENE_HEADER
#define TEST_SCENE_HEADER

#include <FireLight.h>
#include <memory>

#include "../Component/camera_moviment.h"
#include "../Component/Box.h"
#include "../Component/Moviment.h"
#include "../Component/RotComp.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>


class Test_Scene : public FL::Scene
{
public:
	void Init();
	void Update();
	void Debug();
	void Close();

	void LoadModel(std::string path);
	void ProcessNode(aiNode* node, const aiScene* scene);
	void ProcessMesh(aiMesh* mesh, const aiScene* scene);

private:

	std::vector<Mesh> meshes;

};

#endif
