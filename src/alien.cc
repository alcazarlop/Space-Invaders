
#include "alien.h"

Alien::Alien(){
	
}

Alien::~Alien(){

}

void Alien::init(int index, Sprite* sprite){
	
	float inital_pos_x = 48.0f;
	float inital_pos_y = 90.0f;
	float offset = 32.0f; 

	alive = true;
	position.x = inital_pos_x + (index % 11) * offset;
	position.y = inital_pos_y + (index / 11) * offset;

	velocity = {5.0f, 0.0f};

	switch(index / 11){
		case 0: 
			sprite_id = 5; 
			setShape(sprite[5].getWidth(), sprite[5].getHeight());
		break;
		case 1: 
			sprite_id = 7; 
			setShape(sprite[7].getWidth(), sprite[7].getHeight());
		break;
		case 2: 
			sprite_id = 7; 
			setShape(sprite[7].getWidth(), sprite[7].getHeight());
		break;
		case 3: 
			sprite_id = 9; 
			setShape(sprite[9].getWidth(), sprite[9].getHeight());
		break;
		case 4: 
			sprite_id = 9; 
			setShape(sprite[9].getWidth(), sprite[9].getHeight());
		break;
	}

}

void Alien::fire(){


}

void Alien::move(){



}

unsigned char Alien::getID()
{
	return sprite_id;
}