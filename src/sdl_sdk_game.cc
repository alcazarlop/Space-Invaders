
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

}

void Game::handleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE) isRunning = false;
}

void Game::loop()
{

}

void Game::render()
{

	SDL_RenderClear(display.getRender());

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

