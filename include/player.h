
#ifndef __PLAYER_H__
#define __PLAYER_H__ 1

#include "game_entity.h"

class Player : public GameEntity{
	
	public:

		Player();
		~Player();

		void init(float screen_w, float screen_h);
		void input(SDL_Event e, float screen_w);
		void fire();
		bool hasFired();

		GameEntity shot;

	private:

		bool fired;

};

#endif // __PLAYER_H__