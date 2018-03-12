
#ifndef Timer_H
#define Timer_H

#include "SFML\System\Clock.hpp"

class Timer
{
public:
    static void Update();

    static float GetElapsedFrameTime();

    static float GetTime();
private:
    static float ourLastFrameTime;
    static float ourFrameTime;

	static sf::Clock ourTimer;
};

#endif