
#include "sdl_sdk_game.h"
#include <stdio.h>

Game::Game()
{
	isRunning = false;
}

Game::~Game()
{

}

void Game::init()
{

	SDL_Init(SDL_INIT_EVERYTHING);
	display.init();
	isRunning = true;

	//Player
	player.init(display.getRender(), (float) display.getWidth(), (float) display.getHeight());

	//Shield
	shield = (Shield*) calloc(kNumberShield, sizeof(Shield));
	for(int i = 0; i < kNumberShield; ++i){
		(shield + i)->init(display.getRender());
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

	player.draw(display.getRender());
	if(player.hasFired()){
		player.shot.draw(display.getRender());
	}

	for(int j = 0; j < kNumberShield; ++j){
		for(int i = 0; i < kSubsprites; ++i){
			(shield + j)->draw(display.getRender(), 200.0f, 400.0f, &(shield + j)->subsprites[i]);
		}
	}

	SDL_RenderPresent(display.getRender());

}

void Game::exit()
{
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

