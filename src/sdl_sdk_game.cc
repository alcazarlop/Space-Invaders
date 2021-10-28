
#include "sdl_sdk_game.h"
#include <stdio.h>

Game::Game()
{
	isRunning = false;
}

Game::~Game()
{

}

void Game::loadSprites(SDL_Renderer* render){

	sprite = new Sprite[kTotalSprites];

	//Player
	this->sprite[0].loadFromFile("../data/player/player.png", render);

	//Player Shot
	this->sprite[1].loadFromFile("../data/player/player_shot.png", render);

	//Player Death
	this->sprite[2].loadFromFile("../data/player/player_death_1.png", render);
	this->sprite[3].loadFromFile("../data/player/player_death_2.png", render);

	//Shield
	this->sprite[4].loadFromFile("../data/shield/shield.png", render);

	//Alien
	this->sprite[5].loadFromFile("../data/enemies/enemy_1a.png", render);
	this->sprite[6].loadFromFile("../data/enemies/enemy_1b.png", render);
	this->sprite[7].loadFromFile("../data/enemies/enemy_2a.png", render);
	this->sprite[8].loadFromFile("../data/enemies/enemy_2b.png", render);
	this->sprite[9].loadFromFile("../data/enemies/enemy_3a.png", render);
	this->sprite[10].loadFromFile("../data/enemies/enemy_3b.png", render);

	//Alien Death
	this->sprite[11].loadFromFile("../data/enemies/enemy_death.png", render);

	//Alien Shot
	this->sprite[12].loadFromFile("../data/shot/shot_1a.png", render);
	this->sprite[13].loadFromFile("../data/shot/shot_2a.png", render);
	this->sprite[14].loadFromFile("../data/shot/shot_3a.png", render);
	this->sprite[15].loadFromFile("../data/shot/shot_4a.png", render);

	this->sprite[16].loadFromFile("../data/shot/shot_1b.png", render);
	this->sprite[17].loadFromFile("../data/shot/shot_2b.png", render);
	this->sprite[18].loadFromFile("../data/shot/shot_3b.png", render);
	this->sprite[19].loadFromFile("../data/shot/shot_4b.png", render);
	
	this->sprite[20].loadFromFile("../data/shot/shot_1c.png", render);
	this->sprite[21].loadFromFile("../data/shot/shot_2c.png", render);
	this->sprite[22].loadFromFile("../data/shot/shot_3c.png", render);
	this->sprite[23].loadFromFile("../data/shot/shot_4c.png", render);

	//Ufo
	this->sprite[24].loadFromFile("../data/ufo/ufo.png", render);
	this->sprite[25].loadFromFile("../data/ufo/ufo_death.png", render);

}

void Game::init()
{

	SDL_Init(SDL_INIT_EVERYTHING);
	display.init();
	isRunning = true;

	loadSprites(display.getRender());

	//Player
	player.init((float) display.getWidth(), (float) display.getHeight());
	player.setShape(sprite[0].getWidth(), sprite[0].getHeight());
	player.shot.setShape(sprite[1].getWidth(), sprite[1].getHeight());

	//Shield
	shield = new Shield[kShieldNumber];
	if(nullptr == shield){
		printf("Error al inicializar la barrera\n");
	}
	else{
		for(int i = 0; i < kShieldNumber; ++i){
			(shield + i)->init();
			(shield + i)->setShape(sprite[4].getWidth(), sprite[4].getHeight());
		}
	}

	//Alien
	alien = new Alien[kAlienNumber];
	if(nullptr == alien){
		printf("Error al inicializar los aliens\n");
	}
	else{
		for(int i = 0; i < kAlienNumber; ++i){
			(alien + i)->init(i, sprite);
		}
	}

}

void Game::handleEvent()
{
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
	player.input(event, (float) display.getWidth());
}

void Game::loop()
{

	player.fire();

}

void Game::render()
{

	SDL_RenderClear(display.getRender());

	player.draw(display.getRender(), sprite[0].getTexture());
	if(player.hasFired()){
		player.shot.draw(display.getRender(), sprite[1].getTexture());
	}

	for(int j = 0; j < kShieldNumber; ++j){
		for(int i = 0; i < kSubsprites; ++i){
			(shield + j)->draw(display.getRender(), sprite[4].getTexture(), 200.0f, 400.0f, &(shield + j)->subsprites[i]);
		}
	}

	for(int i = 0; i < kAlienNumber; ++i){
		(alien + i)->draw(display.getRender(), sprite[(alien + i)->getID()].getTexture());
	}

	SDL_RenderPresent(display.getRender());

}

void Game::exit()
{
	
	delete[] alien;
	delete[] shield;
	delete[] sprite;

	IMG_Quit();
	SDL_Quit();
}

int Game::run()
{

	init();

	while(running())
	{
		handleEvent();
		loop();
		render();
	}

	exit();

	return 0;
}

bool Game::running()
{
	return isRunning;
}
