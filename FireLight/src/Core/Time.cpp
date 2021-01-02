#include "Time.h"
#include <algorithm>


double Time::m_current_time = 0;
double Time::m_previus_time = 0;
double Time::m_elapsed		= 0.0;
const double Time::DELTA_TIME = 1.0 / 60.0;

Time::Time()
{
}

void Time::Start()
{
	m_previus_time = glfwGetTime();
}

double Time::GetTime()
{
	return m_current_time;
}

double Time::GetDeltaTime()
{
	return std::min(m_elapsed, DELTA_TIME);
}

double Time::GetElapsed()
{
	return m_elapsed;
}

void Time::Calculate()
{
	double current = glfwGetTime();
	m_elapsed = current - m_previus_time;
	m_previus_time = current;
	m_current_time = glfwGetTime();
}

float Time::GetFrameTime()
{
	return 0.0f;
}

void Time::Reset()
{
	m_elapsed -= DELTA_TIME;
}

Time::~Time()
{
}
