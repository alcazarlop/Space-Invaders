
#ifndef __SDL_SDK_TIME_H__
#define __SDL_SDK_TIME_H__ 1

#include <SDL.h>

class Time{

	public:

		Time();
		~Time();

		void reset();
		void update();
		
		float getDeltaTime();
		void setTimeScale(float);
		float getTimeScale();

	private:
		Uint32 startTime;
		Uint32 elapsedTime;
		float deltaTime;
		float timeScale;

};

#endif // __SDL_SDK_TIME_H__
