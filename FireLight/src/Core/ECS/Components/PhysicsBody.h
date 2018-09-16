#ifndef PHYSICSBODY_H
#define PHYSICSBODY_H

#include "../Component.h"
#include <Box2D\Box2D.h>

struct PhysicsBody : Component<PhysicsBody>
{
	PhysicsBody(b2Body* b)
	{
		body = b;
	}

	b2Body* body;
};


#endif