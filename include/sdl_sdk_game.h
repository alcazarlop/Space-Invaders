
#ifndef __SDL_SDK_GAME_H__
#define __SDL_SDK_GAME_H__ 1

#include <SDL.h>
#include "sdl_sdk_sprite.h"
#include "sdl_sdk_window.h"
#include "player.h"
#include "shield.h"

const unsigned char kNumberShield = 1;


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

		SDL_Event event;
		bool isRunning;
		Window display;

		Player player;
		Shield *shield;

};

#endif // __SDL_SDK_GAME_H__