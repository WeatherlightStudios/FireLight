#include "RandomNumber.h"

RandomNumber::RandomNumber()
{
}


int RandomNumber::GaussianRange(int a, int b)
{
	float sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += Range(0.0f, 1.0f);
	}
	sum /= 3;
	int diff = b - a;
	int r = diff * sum;
	return r + a;
}

float RandomNumber::GaussianRange(float a, float b)
{
	float sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += Range(0.0f, 1.0f);
	}
	sum /= 3;
	float diff = b - a;
	float r = diff * sum;
	return r + a;
}

void RandomNumber::SetSeed(int seed)
{
	srand(seed);
}

RandomNumber::~RandomNumber()
{
}
