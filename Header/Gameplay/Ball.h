#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Gameplay_N
{
	class Ball
	{
		private:
			CircleShape ball_sprite;
			const float ball_radius = 10.0f;
			const float ball_pos_x = 500.0f;
			const float ball_pos_y = 500.0f;
		public:
			Ball();
			void update(); // for ball movement 
			void render(RenderWindow *_game_window); // for rendering ball on the window

	};
}