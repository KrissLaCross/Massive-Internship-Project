#include "Timer.h"

float Timer::ourLastFrameTime = 0.0f;
float Timer::ourFrameTime = 0.0f;
sf::Clock Timer::ourTimer;

void Timer::Update()
{
	ourLastFrameTime = ourFrameTime;
	ourFrameTime = static_cast<float>(ourTimer.getElapsedTime().asMilliseconds()) / 1000.f;
}

float Timer::GetElapsedFrameTime()
{
    return ourFrameTime - ourLastFrameTime;
}

float Timer::GetTime()
{
    return ourFrameTime;
}
