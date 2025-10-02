#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "Boundary.h"
#include "../Utility/TimeService.h"
#include "../UI/UIService.h"
#include "../Sound/SoundManager.h"

namespace Gameplay_N
{
	class GameplayManager
	{
		private:
			void initialize();

		public:
			Ball* ball;
			Paddle* paddle_1;
			Paddle* paddle_2;
			Boundary* boundaries;
			Utility_N::TimeService *timeService;
			UI_N::UIService *UIService;
			Sound_N::SoundManager *soundManager;

			GameplayManager();
			void update();
			void render(RenderWindow* _game_window);
	};
}