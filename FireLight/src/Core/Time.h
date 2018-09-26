#ifndef TIME_HEADER
#define TIME_HEADER

#include <GLFW\glfw3.h>

class Time
{
public:
	Time();
	~Time();

	//Engine Staff
	static void Start();

	static double GetLag();

	static void Calculate();

	static void Reset();

	//GameLogic
	static double GetTime();
	static double GetDeltaTime();



private:

	static double m_current_time;
	static double m_previus_time;

	static double m_lag;

	static double delta_time;

};


#endif

