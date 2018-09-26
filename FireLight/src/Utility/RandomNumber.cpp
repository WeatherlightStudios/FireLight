#include "RandomNumber.h"



RandomNumber::RandomNumber()
{
}


template <class T>
T RandomNumber::Range(T a, T b)
{
	T random = ((T)rand()) / (T)RAND_MAX;
	T diff = b - a;
	T r = random * diff;
	return a + r;
}


RandomNumber::~RandomNumber()
{
}
