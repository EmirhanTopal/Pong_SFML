#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Boundary.h"

namespace Gameplay_N
{
	class GameplayManager
	{
		private:
			float player1_pos_x = 40.0f;
			float player1_pos_y = 300.0f;

			float player2_pos_x = 1210.0f;
			float player2_pos_y = 300.0f;

			void initialize();

		public:
			Ball* ball;
			Paddle* paddle_1;
			Paddle* paddle_2;
			Boundary* boundaries;

			GameplayManager();
			void update();
			void render(RenderWindow* _game_window);
	};
}