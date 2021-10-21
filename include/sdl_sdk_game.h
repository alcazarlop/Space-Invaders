
#ifndef __SDL_SDK_GAME_H__
#define __SDL_SDK_GAME_H__ 1

#include <SDL.h>
#include "sdl_sdk_sprite.h"
#include "sdl_sdk_window.h"

class Game{
	
	public:
		Game();
		~Game();

		void init();
		void handleEvent();
		void loop();
		void render();
		void exit();
		int run();

		bool running();

	private:
		bool isRunning;
		Sprite sprite;
		Window display;

};

#endif // __SDL_SDK_GAME_H__