#include "Time.h"


double Time::m_current_time = 0;
double Time::m_previus_time = 0;
double Time::m_lag = 0.0;
double Time::delta_time = 1.0 / 60.0;

Time::Time()
{
}

void Time::start()
{
	m_previus_time = glfwGetTime();
	m_lag = 0.0;
}

double Time::GetTime()
{
	return m_current_time;
}

double Time::GetDeltaTime()
{
	return delta_time;
}

double Time::GetLag()
{
	return m_lag;
}

void Time::Calculate()
{
	double current = glfwGetTime();
	double elapsed = current - m_previus_time;
	m_previus_time = current;
	m_lag += elapsed;

	m_current_time = glfwGetTime();
}

void Time::reset()
{
	m_lag -= delta_time;
}




Time::~Time()
{
}
