#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "Camera.h"

class Renderable
{
public:
	Renderable();

	virtual void Draw(Camera *camera) = 0;

	~Renderable();


private:


};

#endif

