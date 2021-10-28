
#ifndef __SDL_SDK_GAME_H__
#define __SDL_SDK_GAME_H__ 1

#include <SDL.h>
#include "sdl_sdk_sprite.h"
#include "sdl_sdk_window.h"
#include "sdl_sdk_time.h"
#include "player.h"
#include "shield.h"
#include "alien.h"

const unsigned char kShieldNumber = 1;
const unsigned char kAlienNumber = 55;
const unsigned char kTotalSprites = 26;

class Game{
	
	public:
		
		Game();
		~Game();

		void init();
		void loadSprites(SDL_Renderer* render);
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
		Sprite *sprite;
		Shield *shield;
		Alien *alien;

};

#endif // __SDL_SDK_GAME_H__