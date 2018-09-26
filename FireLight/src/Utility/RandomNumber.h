#ifndef RANDOMNUMBER_H
#define  RANDOMNUMBER_H
#include <iostream>

class RandomNumber
{
public:
	RandomNumber();
	~RandomNumber();


	static int IntRange(int a, int b);
	static float Range(float a, float b);
	static int GaussianRangeInt(int a, int b);
	static float GaussianRange(float a, float b);
};

#endif