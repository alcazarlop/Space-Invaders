
#include "game_entity.h"

GameEntity::GameEntity(){

}

GameEntity::~GameEntity(){
	
}

void GameEntity::setVelocity(SDL_FPoint vel){
	velocity = vel;
}

void GameEntity::setVelocity(float x, float y){
	velocity = {x, y};
}

void GameEntity::setPosition(SDL_FPoint pos){
	position = pos;
}

void GameEntity::setPosition(float x, float y){
	position = {x, y};
}

void GameEntity::draw(SDL_Renderer* render){
	sprite.drawTexture(render, position);
}
