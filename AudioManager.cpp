#include "AudioManager.h"

AudioManager::AudioManager()
{
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
}

AudioManager::~AudioManager()
{
	Mix_CloseAudio();
}

void AudioManager::loadSound(const std::string& id, const std::string& fileName)
{
	sounds_.emplace(id, SoundPtr(Mix_LoadWAV(fileName.c_str()), Mix_FreeChunk));
}

void AudioManager::loadMusic(const std::string& id, const std::string& fileName)
{
	music_.emplace(id, MusicPtr(Mix_LoadMUS(fileName.c_str()), Mix_FreeMusic));
}

void AudioManager::playSound(const std::string& id)
{
	Mix_PlayChannel(-1, sounds_[id].get(), 0);
}

void AudioManager::playMusic(const std::string& id)
{
	Mix_PlayMusic(music_[id].get(), 0);
}

void AudioManager::pauseMusic()
{
	Mix_PauseMusic();
}

void AudioManager::resumeMusic()
{
	Mix_ResumeMusic();
}

void AudioManager::stopMusic()
{
	Mix_HaltMusic();
}

void AudioManager::removeSound(const std::string& id)
{
	sounds_.erase(id);
}

void AudioManager::removeMusic(const std::string& id)
{
	music_.erase(id);
}