
#ifndef __GAME_ENTITY_H__
#define __GAME_ENTITY_H__ 1

#include <SDL.h>
#include <SDL_image.h>

class GameEntity{

	public: 

		GameEntity();
		~GameEntity();

		void setVelocity(SDL_FPoint vel);
		void setVelocity(float x, float y);
		void setPosition(SDL_FPoint pos);
		void setPosition(float x, float y);
		void setShape(float x, float y);

		void draw(SDL_Renderer* render, SDL_Texture* texture);

	public:

		SDL_FPoint position;
		SDL_FPoint velocity;
		SDL_FPoint shape;

};

#endif // __GAME_ENTITY_H__