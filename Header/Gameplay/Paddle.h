#pragma once
#include <SFML/Graphics.hpp>
#include "../Event/Event.h"
#include "../Utility/TimeService.h"

using namespace sf;

namespace Gameplay_N
{
	class Paddle
	{
		private:
			RectangleShape paddle_sprite;
			const float paddle_width = 20;
			const float paddle_height = 140;

			float paddle_speed_x = 0;
			float paddle_speed_y = 200.0f;
			Vector2f velocity = Vector2f(paddle_speed_x, paddle_speed_y);

			void paddle_move(Event_N::EventManager *_event_manager, sf::Keyboard::Key _upKey, sf::Keyboard::Key _downKey, Utility_N::TimeService* _time_service);

		public:
			Paddle(float _pos_x, float _pos_y);
			void update(Event_N::EventManager *_event_manager, sf::Keyboard::Key _upKey, sf::Keyboard::Key _downKey, Utility_N::TimeService* _time_service);
			void render(RenderWindow* _game_window);
			RectangleShape getPaddleSprite();
	};
}
