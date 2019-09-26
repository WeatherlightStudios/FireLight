#ifndef RANDOMNUMBER_H
#define  RANDOMNUMBER_H
#include <iostream>

class RandomNumber
{
public:

	// Returns an int random number between a (inclusive) and b (exclusive)
	static inline int Range(const int a, const int b)
	{
		return (rand() % (b - a)) + a;
	}
	// Returns a float random number between a (inclusive) and b (exclusive)
	static inline float Range(const float a, const float b)
	{
		return ((b - a) * (((float)rand()) / (float)RAND_MAX)) + a;
	}

	// Returns an int random number between a (inclusive) and b (exclusive) using a Gaussian distribution
	static int GaussianRange(int a, int b);
	// Returns a float random number between a (inclusive) and b (exclusive) using a Gaussian distribution
	static float GaussianRange(float a, float b);
	// Sets the random seed to start RNG
	static void SetSeed(int seed);

};

#endif