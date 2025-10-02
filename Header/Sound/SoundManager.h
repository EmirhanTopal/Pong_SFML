#pragma once
#include <SFML/Audio.hpp>

namespace Sound_N
{
	enum SoundType
	{
		BALL_BOUNCE,
	};

	class SoundManager
	{
		private:
			static sf::Music backgroundMusic;
			static sf::Sound soundEffect;
			static sf::SoundBuffer ballBounce;
			
			static const std::string backgroundMusicPath;
			static const std::string ballBouncePath;
			static float musicVolume;

			static void loadSoundFromFile();
			static void playBackgroundMusic();

		public:
			static void initialize();
			static void playSoundEffect(SoundType _sound_type);
	};
}