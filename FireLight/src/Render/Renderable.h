#ifndef RENDERABLE_H
#define RENDERABLE_H

#include "Camera2D.h"

class Renderable
{
public:
	Renderable();

	virtual void Draw(Camera2D *camera) = 0;

	~Renderable();


private:


};

#endif

