#ifndef TIME_HEADER
#define TIME_HEADER

#include <GLFW\glfw3.h>
#define SMOOTH_AMMOUNT 100


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
	static float GetFrameRate();

private:

	static double m_current_time;
	static double m_previus_time;
	static double m_elapsed;
	static float m_frame_rate;

	static float m_frame_times[];


	static int m_frame_counter;
	const static double DELTA_TIME;
};


#endif

