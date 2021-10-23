
#ifndef __GAME_ENTITY_H__
#define __GAME_ENTITY_H__ 1

#include <SDL.h>
#include "sdl_sdk_sprite.h"

class GameEntity{

	public: 

		GameEntity();
		~GameEntity();

		void setVelocity(SDL_FPoint vel);
		void setVelocity(float x, float y);
		void setPosition(SDL_FPoint pos);
		void setPosition(float x, float y);

		void draw(SDL_Renderer* render);

	public:

		SDL_FPoint position;
		SDL_FPoint shape;
		SDL_FPoint velocity;

		Sprite sprite;

};

#endif // __GAME_ENTITY_H__