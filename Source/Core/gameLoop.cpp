#include "../../Header/Core/GameLoop.h"

namespace Core_N
{
	void GameLoop::initialize()
	{
		game_window_manager = new GameWindowManager(); //allocate memory for GameWindowManager with new keyword because of game_window_manager is a pointer.
		event_manager = new Event_N::EventManager(); // allocate memory for EventManager with new keyword because of event_manager is a pointer.
		game_window_manager->initialize(); // initalize the game window.
	}

	bool GameLoop::isGameRunning() // game loop depends on game window therefore we use isGameRunning function fo game_window_manager.
	{
		return game_window_manager->isGameRunning();
	}

	void GameLoop::poolEvent(RenderWindow *_game_window)
	{
		return event_manager->PoolEvents(game_window_manager->getGameWindow());
	}

	void GameLoop::update()
	{

	}

	void GameLoop::render()
	{
		game_window_manager->clearGameWindow();
		game_window_manager->displayGameWindow();
	}
}