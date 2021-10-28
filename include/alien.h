
#ifndef __ALIEN_H__
#define __ALIEN_H__ 1

#include "game_entity.h"
#include "sdl_sdk_sprite.h"

class Alien : public GameEntity{
	
	public:

		Alien();
		~Alien();

		void init(int index, Sprite* sprite);
		void move();
		void fire();

		unsigned char getID();

		GameEntity shot;

	private:

		unsigned char sprite_id;
		bool alive;

};

#endif // __ALIEN_H__