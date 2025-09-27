#pragma once
#include <SFML/Graphics.hpp>
#include "../Event/Event.h"

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
			float paddle_speed_y = 0.05f;
			Vector2f velocity = Vector2f(paddle_speed_x, paddle_speed_y);
			
			void paddle_move(Event_N::EventManager *_event_manager, int player_num);
		public:
			Paddle(float _pos_x, float _pos_y);
			void update(Event_N::EventManager *_event_manager, int player_num);
			void render(RenderWindow* _game_window);
	};
}
