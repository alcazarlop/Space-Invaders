
#include "shield.h"

Shield::Shield(){

}

Shield::~Shield(){


}

void Shield::init(SDL_Renderer* render){

	int width = 16, height = 12;
	int aux_x = 0 , aux_y = 0;

	sprite.loadFromFile("../data/shield/shield.png", render);

	for(int i = 0; i < kSubsprites; ++i){
		subsprites[i] = {aux_x, aux_y, width, height};
		enable[i] = true;
		aux_x += width;
		if(aux_x >= width * 4){
			aux_y += height;
			aux_x = 0;
		}
	}
}

void Shield::draw(SDL_Renderer* render, float x, float y, SDL_Rect* src){

	SDL_FRect renderQuad = {x + (float) src->x, y + (float) src->y, (float) src->w, (float) src->h};
	SDL_RenderCopyExF(render, sprite.getTexture(), src, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);

}

