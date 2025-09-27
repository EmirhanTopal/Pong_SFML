#include "../../Header/Gameplay/Gameplay.h"

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
		ball->render(_game_window);
		paddle_1->render(_game_window);
		paddle_2->render(_game_window);
		boundaries->render(_game_window);
	}

	void GameplayManager::initialize()
	{
		ball = new Ball();
		paddle_1 = new Paddle(player1_pos_x, player1_pos_y);
		paddle_2 = new Paddle(player2_pos_x, player2_pos_y);
		boundaries = new Boundary();
	}
}