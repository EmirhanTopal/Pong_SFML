#include "../../Header/Gameplay/Gameplay.h"
#include "../../Header/Utility/TimeService.h"
#include "../../Header/UI/UIService.h"

namespace Gameplay_N
{
	GameplayManager::GameplayManager()
	{
		initialize();
	}

	void GameplayManager::update()
	{

	}

	void GameplayManager::render(RenderWindow* _game_window)
	{
		boundaries->render(_game_window);
		ball->render(_game_window);
		paddle_1->render(_game_window);
		paddle_2->render(_game_window);
		UIService->render(_game_window);
	}

	void GameplayManager::initialize()
	{
		ball = new Ball();
		paddle_1 = new Paddle(Paddle::player1_pos_x, Paddle::player1_pos_y);
		paddle_2 = new Paddle(Paddle::player2_pos_x, Paddle::player2_pos_y);
		boundaries = new Boundary();
		timeService = new Utility_N::TimeService();
		UIService = new UI_N::UIService();
	}
}