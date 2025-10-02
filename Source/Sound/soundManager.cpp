#include "../../Header/Sound/SoundManager.h"
#include <iostream>

namespace Sound_N
{
	sf::Music SoundManager::backgroundMusic;
	sf::Sound SoundManager::soundEffect;
	sf::SoundBuffer SoundManager::ballBounce;

	const std::string SoundManager::ballBouncePath = "Assets/Sounds/Ball_Bounce.wav";
	const std::string SoundManager::backgroundMusicPath = "Assets/Sounds/Pong_BGM.mp3";
	float SoundManager::musicVolume = 10;

	void SoundManager::initialize()
	{
		loadSoundFromFile();
		playBackgroundMusic();
	}

	void SoundManager::loadSoundFromFile()
	{
		if (!ballBounce.loadFromFile(ballBouncePath))
		{
			std::cerr << "Error loading sound file: " << ballBouncePath << std::endl;
		}
	}

	void SoundManager::playSoundEffect(SoundType _sound_type)
	{
		switch (_sound_type)
		{
			case SoundType::BALL_BOUNCE:
				soundEffect.setBuffer(ballBounce);
				soundEffect.play();
				break;
			default:
				std::cerr << "Invalid sound type" << std::endl;
				break;
		}
	}

	void SoundManager::playBackgroundMusic()
	{
		if (!backgroundMusic.openFromFile(backgroundMusicPath))
		{
			std::cout << "File could not be opened" << std::endl;
			return;
		}
		backgroundMusic.setLoop(true);
		backgroundMusic.setVolume(musicVolume);
		backgroundMusic.play();
		
	}
}