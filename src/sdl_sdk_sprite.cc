
#include "sdl_sdk_sprite.h"

Sprite::Sprite()
{
	texture = nullptr;
	shape.x = 0;
	shape.y = 0;
}

Sprite::~Sprite() 
{
	release();
}

float Sprite::getWidth()
{
	return shape.x;
}

float Sprite::getHeight() 
{ 
	return shape.y; 
}

void Sprite::release()
{
	SDL_DestroyTexture(texture); texture = nullptr;
	shape.x = 0;
	shape.y = 0;
}

SDL_Texture* Sprite::loadFromFile(char* path, SDL_Renderer* renderer) 
{

	SDL_Surface* loadedTexture = IMG_Load(path); //The texture loaded
	SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedTexture); //Conver surface to texture

	//Dimensions
	shape.x = (float) loadedTexture->w; 
	shape.y = (float) loadedTexture->h;

	SDL_FreeSurface(loadedTexture); loadedTexture = nullptr; //Free the previous texture

	texture = newTexture;

	return texture;

}

SDL_Texture* Sprite::getTexture()
{
	return texture;
}

SDL_FRect Sprite::transform(float posx, float posy, float w, float h)
{
	return rect = { posx, posy, w, h };
}

void Sprite::drawTexture(SDL_Renderer* renderer, SDL_FRect dstRect, double angle, SDL_FPoint* center = nullptr)
{
	SDL_RenderCopyExF(renderer, texture, nullptr, &dstRect, angle, center, SDL_FLIP_NONE);
}

void Sprite::drawTexture(SDL_Renderer* renderer, SDL_FPoint pos)
{
	SDL_FRect dstRect = {pos.x , pos.y, shape.x, shape.y};
	SDL_RenderCopyExF(renderer, texture, nullptr, &dstRect, 0.0, nullptr, SDL_FLIP_NONE);
}
