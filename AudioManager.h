#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <SDL_mixer.h>

#include <map>
#include <memory>
#include <string>

typedef std::unique_ptr<Mix_Chunk, void(*)(Mix_Chunk*)> SoundPtr;
typedef std::unique_ptr<Mix_Music, void(*)(Mix_Music*)> MusicPtr;

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	void loadSound(const std::string& id, const std::string& fileName);
	void loadMusic(const std::string& id, const std::string& fileName);

	void playSound(const std::string& id);
	void playMusic(const std::string& id);

	void pauseMusic();
	void resumeMusic();
	void stopMusic();

	void removeSound(const std::string& id);
	void removeMusic(const std::string& id);

private:
	std::map<std::string, SoundPtr> sounds_;
	std::map<std::string, MusicPtr> music_;
};

#endif