#ifndef RANDOMNUMBER_H
#define  RANDOMNUMBER_H
class RandomNumber
{
public:
	RandomNumber();
	~RandomNumber();

	template <class T>
	static T Range(T a, T b);

};

#endif