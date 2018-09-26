#include "RandomNumber.h"

RandomNumber::RandomNumber()
{
}

int RandomNumber::IntRange(int a, int b) {
	auto diff = b - a;
	auto n = rand() % diff;
	return n + a;
}

float RandomNumber::Range(float a, float b)
{
	float random = ((float)rand()) / (float)RAND_MAX;
	float range = b - a;
	float r = range * random;
	return r + a;
}



int RandomNumber::GaussianRangeInt(int a, int b)
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

RandomNumber::~RandomNumber()
{
}
