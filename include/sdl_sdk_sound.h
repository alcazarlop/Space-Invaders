
#ifndef __SDL_SDK_SOUND_H__
#define __SDL_SDK_SOUND_H__ 1

#include <SDL_mixer.h>

class Sound{

	public:
		Sound();
		~Sound();

		void loadSound(const char* file);
		void loadMusic(const char* file);

		void play(int channel, Mix_Chunk* chk, int loops);
		void play(Mix_Music* music, int loops);

		Mix_Chunk* getChunk();
		Mix_Music* getMusic();

		void releaseSound(Mix_Chunk* chunk);
		void releaseMusic(Mix_Music* mus);

	private:
		Mix_Chunk* chunk; 
		Mix_Music* music;

};

#endif