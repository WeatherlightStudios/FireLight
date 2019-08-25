#ifndef RANDOMNUMBER_H
#define  RANDOMNUMBER_H
#include <iostream>

class RandomNumber
{
public:
	RandomNumber();
	~RandomNumber();


	static inline int Range(const int a, const int b)
	{
		return (rand() % (b - a)) + a;
	}
	static inline float Range(const float a, const float b)
	{
		return ((b - a) * (((float)rand()) / (float)RAND_MAX)) + a;
	}
	static int GaussianRange(int a, int b);
	static float GaussianRange(float a, float b);
	static void SetSeed(int seed);

};

#endif