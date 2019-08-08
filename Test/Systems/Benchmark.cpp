#include "Benchmark.h"



Benchmark::Benchmark()
{
	registerComponent(Transform::ID);
	registerComponent(Movement::ID);
}


void Benchmark::Update(uint32_t entity)
{
	Transform* transform = World::getComponent<Transform>(entity);
	Movement* moviment = World::getComponent<Movement>(entity);



			if (transform->Position.y >= 300)
			{
				moviment->VeclotyY *= -1;
			}

			if (transform->Position.x >= 400)
			{
				moviment->VeclotyX *= -1;
			}
		
		
			if (transform->Position.y <= -300)
			{
				moviment->VeclotyY *= -1;
			}

			if (transform->Position.x <= -400)
			{
				moviment->VeclotyX *= -1;
			}


	transform->Position.x += moviment->VeclotyX;
	transform->Position.y += moviment->VeclotyY;

}


Benchmark::~Benchmark()
{
}
