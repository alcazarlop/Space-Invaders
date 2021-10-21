
#ifndef __GAME_ENTITY_H__
#define __GAME_ENTITY_H__ 1

#include <SDL.h>
#include "sdl_sdk_input.h"
#include "sdl_sdk_sprite.h"

class GameEntity{

	public: 

		GameEntity();
		GameEntity(SDL_FPoint pos, SDL_FPoint shp);
		GameEntity(float x, float y, float w, float h);
		GameEntity(SDL_FRect rect);
		~GameEntity();

		void setVelocity(SDL_FPoint vel);
		void setVelocity(float x, float y);
		void setPosition(SDL_FPoint pos);
		void setPosition(float x, float y);
		void setShape(SDL_FPoint shp);
		void setShape(float x, float y);

	protected:

		SDL_FPoint position;
		SDL_FPoint shape;
		SDL_FPoint velocity;

		Input input;
		Sprite sprite;

};

#endif // __GAME_ENTITY_H__