#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Gameplay_N
{
	class Paddle
	{
		private:
			RectangleShape paddle_sprite;
			const float paddle_width = 20;
			const float paddle_height = 140;
		public:
			Paddle(float _pos_x, float _pos_y);
			void update();
			void render(RenderWindow* _game_window);
	};
}
