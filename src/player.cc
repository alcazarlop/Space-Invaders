
#include "player.h"

Player::Player(){

}

Player::~Player(){

}

void Player::init(SDL_Renderer* render, float screen_w, float screen_h){
	position = { screen_w * 0.5f, screen_h * 0.9f };
	velocity = {6.0f, 6.0f };
	fired = false;
	sprite.loadFromFile("../data/player/player.png", render);

	shot.position = {-100.0f, -100.0f};
	shot.velocity = {15.0f, 15.0f};
	shot.sprite.loadFromFile("../data/player/player_shot.png", render);
}

void Player::input(SDL_Event e, float screen_w){
	switch(e.type){
		case SDL_KEYDOWN: {
			switch(e.key.keysym.sym){
				case SDLK_LEFT: {
					if(position.x - velocity.x >= 0.0f){
						position.x -= velocity.x;
					}
					break;
				}
				case SDLK_RIGHT: {
					if(position.x + velocity.x + sprite.getWidth() <= screen_w){
						position.x += velocity.x;
					}
					break;
				}
				case SDLK_SPACE:{
					fired = true;
					break;
				}
			}
		}
	}
}

void Player::fire(){
	if(fired){
		shot.position.y -= shot.velocity.y;
		if(shot.position.y <= 0.0f){
			fired = false;
		}
	}
	else{
		shot.position.x = position.x + sprite.getWidth() * 0.45f;
		shot.position.y = position.y - shot.sprite.getHeight();

	}
}

bool Player::hasFired()
{
	return fired;
}
