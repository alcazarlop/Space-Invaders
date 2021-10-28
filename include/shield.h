
#ifndef __SHIELD_H__
#define __SHIELD_H__ 1

#include "game_entity.h"

const unsigned char kSubsprites = 16;

class Shield : public GameEntity{
	
	public:

		Shield();
		~Shield();

		void init();
		void draw(SDL_Renderer* render, SDL_Texture* texture, float x, float y, SDL_Rect* src);
		SDL_Rect subsprites[kSubsprites];

	private:

		bool enable[kSubsprites];

};

#endif // __SHIELD_H__