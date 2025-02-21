// Time.cpp

#include "Engine/Time.h"

#include <GLFW/glfw3.h>

Time::Time() = default;
Time::~Time() = default;

void Time::Update()
{
	m_currentTime = glfwGetTime();
	m_frameCount++;

	if (m_currentTime - m_previousTime >= 1.0)
	{
		m_frameRate = m_frameCount;
		m_frameCount = 0;
		m_previousTime = m_currentTime;
	};
};

int Time::GetFrameRate() const
{
	return m_frameRate;
};
