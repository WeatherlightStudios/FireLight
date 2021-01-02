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
	static void Calculate();
	static void Reset();

	//GameLogic
	static double GetElapsed();
	static double GetTime();
	static double GetDeltaTime();
	static float GetFrameTime();

private:

	static double m_current_time;
	static double m_previus_time;
	static double m_elapsed;
	const static double DELTA_TIME;
};


#endif

