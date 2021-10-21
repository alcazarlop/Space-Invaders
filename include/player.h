
#ifndef __PLAYER_H__
#define __PLAYER_H__ 1

#include "game_entity.h"

class Player : GameEntity{
	
	public:

		Player();
		~Player();

		void init();
		void move(SDL_Event& e);
		void shot();

};

#endif // __PLAYER_H__