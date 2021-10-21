
#include "game_entity.h"

GameEntity::GameEntity(){
	position = {0.0f, 0.0f};
	shape = {0.0f, 0.0f};
}

GameEntity::GameEntity(SDL_FPoint pos, SDL_FPoint shp){
	position = pos;
	shape = shp;
}

GameEntity::GameEntity(float x, float y, float w, float h){
	position = {x, y};
	shape = {w, h};
}

GameEntity::GameEntity(SDL_FRect rect){
	position = {rect.x, rect.y};
	shape = {rect.w, rect.h};
}

GameEntity::~GameEntity(){}

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

void GameEntity::setShape(SDL_FPoint shp){
	shape = shp;
}

void GameEntity::setShape(float x, float y){
	shape = {x, y};
}

