
#include "sdl_sdk_sprite.h"

Sprite::Sprite()
{
	texture = nullptr;
	rect.w = 0;
	rect.h = 0;
}

Sprite::~Sprite() 
{
	release();
}

float Sprite::getWidth()
{
	return rect.w;
}

float Sprite::getHeight() 
{ 
	return rect.h; 
}

void Sprite::release()
{
	SDL_DestroyTexture(texture); texture = nullptr;
	rect.w = 0;
	rect.h = 0;
}

SDL_Texture* Sprite::loadFromFile(char* path, SDL_Renderer* renderer) 
{

	SDL_Surface* loadedTexture = IMG_Load(path); //The texture loaded
	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedTexture); //Conver surface to texture

	//Dimensions
	rect.w = (float) loadedTexture->w; 
	rect.h = (float) loadedTexture->h;

	SDL_FreeSurface(loadedTexture); loadedTexture = nullptr; //Free the previous texture

	texture = newTexture;

	return texture;

}

SDL_Texture* Sprite::getTexture()
{
	return texture;
}

void Sprite::drawTexture(SDL_Renderer* renderer, SDL_FRect dstRect, double angle, SDL_FPoint* center = nullptr)
{
	SDL_RenderCopyExF(renderer, texture, nullptr, &dstRect, angle, center, SDL_FLIP_NONE);
}

void Sprite::drawTexture(SDL_Renderer* renderer, SDL_FPoint pos)
{
	SDL_FRect dstRect = {pos.x , pos.y, rect.w, rect.h};
	SDL_RenderCopyExF(renderer, texture, nullptr, &dstRect, 0.0, nullptr, SDL_FLIP_NONE);
}
