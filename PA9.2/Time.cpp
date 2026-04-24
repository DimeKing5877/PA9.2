#include "Time.hpp"

Time::Time()
{
	nextDeltaTime();
}

Time::~Time()
{}

void Time::nextDeltaTime()
{
	deltaTime = clock.restart().asSeconds();
}

float Time::getDeltaTime() const
{
	return deltaTime;
}
