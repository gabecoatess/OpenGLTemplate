// Time.h

#ifndef TIME_H
#define TIME_H

class Time
{
public:
	Time();
	~Time();

	void Update();
	int GetFrameRate() const;

private:
	int m_frameRate = 0;
	int m_frameCount = 0;
	double m_currentTime = 0;
	double m_previousTime = 0;
};

#endif
