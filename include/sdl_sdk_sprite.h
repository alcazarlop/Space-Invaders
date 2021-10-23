
#ifndef __SDL_SDK_SPRITE_H__
#define __SDL_SDK_SPRITE_H__ 1

#include <SDL.h>
#include <SDL_image.h>

class Sprite{
	
	public: 

		Sprite();
		~Sprite();

		void release();
		SDL_Texture* loadFromFile(char* path, SDL_Renderer* renderer);
		SDL_Texture* getTexture();
		SDL_FRect transform(float posx, float posy, float w, float h);
		void drawTexture(SDL_Renderer* renderer, SDL_FRect dstRect, double angle, SDL_FPoint* center);
		void drawTexture(SDL_Renderer* renderer, SDL_FPoint pos);

		float getWidth();
		float getHeight();

	private:

		SDL_Texture* texture;
		SDL_FRect rect;
		SDL_FPoint shape;

};

#endif // __SDL_SDK_SPRITE_H__