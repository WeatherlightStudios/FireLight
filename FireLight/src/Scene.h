#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
	Scene();
	~Scene();

	virtual void Init();
	virtual void Update();
	virtual void Close();

};

#endif

