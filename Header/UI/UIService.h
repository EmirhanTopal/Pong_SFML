#pragma once
#include <SFML/Graphics.hpp>

namespace UI_N
{
	class UIService
	{
		private:
			sf::Font font;
			sf::Text left_score_text;
			sf::Text right_score_text;
			
			std::string font_texture_path = "Assets/Fonts/Aloevera-OVoWO.ttf";

			float left_score_pos_x = 560.0f;
			float left_score_pos_y = 60.0f;

			float right_score_pos_x = 1360.0f;
			float right_score_pos_y = 60.0f;

			int font_size = 40;
			sf::Color font_color = sf::Color::White;
			std::string initial_string = "00";

			int player_1 = 0;
			int player_2 = 0;

			void loadFontTexture();
			void createLeftScoreBoard();
			void createRightScoreBoard();

		public:
			UIService();
			void initialize();
			void render(sf::RenderWindow* _game_window);
	};
}