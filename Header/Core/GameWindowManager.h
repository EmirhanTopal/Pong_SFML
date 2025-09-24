#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Core_N
{
	class GameWindowManager
	{
		private:
			int game_window_width = 1280;
			int game_window_height = 720;

			std::string game_title = "SFML-Pong-Game";

			RenderWindow* game_Window;

			void createGameWindow();
		public:
			void initialize();
			RenderWindow* getGameWindow();
			bool isGameRunning();
			void render();
	};
}