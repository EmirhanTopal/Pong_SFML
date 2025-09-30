#include "../../Header/UI/UIService.h"

namespace UI_N
{
	UIService::UIService()
	{
		initialize();
	}

	void UIService::initialize()
	{
		loadFontTexture();
		createLeftScoreBoard();
		createRightScoreBoard();
	}

	void UIService::update(int _player_1_score, int _player_2_score)
	{
		left_score_text.setString(scoreBoardUpdateText(_player_1_score));
		right_score_text.setString(scoreBoardUpdateText(_player_2_score));
	}

	void UIService::render(sf::RenderWindow *_game_window)
	{
		_game_window->draw(left_score_text);
		_game_window->draw(right_score_text);
	}

	void UIService::loadFontTexture()
	{
		font.loadFromFile(font_texture_path);
	}

	void UIService::createLeftScoreBoard()
	{
		left_score_text.setFont(font);
		left_score_text.setFillColor(font_color);
		left_score_text.setPosition(left_score_pos_x, left_score_pos_y);
		left_score_text.setCharacterSize(font_size);
		left_score_text.setString(initial_string);
	}

	void UIService::createRightScoreBoard()
	{
		right_score_text.setFont(font);
		right_score_text.setFillColor(font_color);
		right_score_text.setPosition(right_score_pos_x, right_score_pos_y);
		right_score_text.setCharacterSize(font_size);
		right_score_text.setString(initial_string);
	}

	sf::String UIService::scoreBoardUpdateText(int _player_score)
	{
		return (_player_score < 10 ? "0" : "") + std::to_string(_player_score);
	}
}