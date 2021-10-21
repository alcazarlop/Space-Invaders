
#include "sdl_sdk_time.h"

Time::Time()
{
  reset();
  timeScale = 1.0f;
}

Time::~Time()
{

}

void Time::reset()
{
  startTime = SDL_GetTicks();
  elapsedTime = 0;
  deltaTime = 0.0f;
}

float Time::getDeltaTime()
{
  return deltaTime;
}

void Time::setTimeScale(float t)
{
  timeScale = t;
}

float Time::getTimeScale()
{
  return timeScale;
}

void Time::update()
{
  elapsedTime = SDL_GetTicks() - startTime;
  deltaTime = elapsedTime * 0.001f;
}