
#include "sdl_sdk_sound.h"

Sound::Sound()
{
	chunk = nullptr;
	music = nullptr;
}

Sound::~Sound()
{

}

void Sound::loadSound(const char* file)
{
	chunk = Mix_LoadWAV(file);
}

void Sound::loadMusic(const char* file)
{
	music = Mix_LoadMUS(file);
}

void Sound::play(int channel, Mix_Chunk* chk, int loops)
{
	Mix_PlayChannel(channel, chk, loops);
}

void Sound::play(Mix_Music* mus, int loops)
{
	Mix_PlayMusic(mus, loops);
}

Mix_Chunk* Sound::getChunk()
{
	return chunk;
}

Mix_Music* Sound::getMusic()
{
	return music;
}

void Sound::releaseSound(Mix_Chunk* chk)
{
	if(chk){
		Mix_FreeChunk(chk);
		chk = nullptr; 
	}
}

void Sound::releaseMusic(Mix_Music* mus)
{
	if(mus)
	{
		Mix_FreeMusic(mus); 
		mus = nullptr;
	}
}