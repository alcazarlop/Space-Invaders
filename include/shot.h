
#ifndef __SHOT_H__
#define __SHOT_H__ 1

#include "game_entity.h"

class Shot : GameEntity{
	
	public:
		Shot();
		~Shot();

		void init();
		void move();

}

#endif // __SHOT_H__