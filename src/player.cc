
#include "player.h"

Player::Player(){

}

Player::~Player(){

}

void Player::init(){




}

void Player::move(SDL_Event& e){
	switch(e.type){
		case SDL_KEYDOWN: {
			switch(e.key.keysym.sym){
				case SDLK_LEFT: {
					position.x -= velocity.x;
					break;
				}
				case SDLK_RIGHT: {
					position.x += velocity.x;
					break;
				}
				case SDLK_UP: {
					position.y -= velocity.y;
					break;
				}
				case SDLK_DOWN: {
					position.y += velocity.y;
					break;
				}
			}
		}
	}
}

void Player::shot(){


	
}