#include "../../Header/Core/GameWindowManager.h"

namespace Core_N
{
	void GameWindowManager::initialize()
	{
		game_Window = new RenderWindow();

		createGameWindow();
	}

	void GameWindowManager::createGameWindow()
	{
		game_Window->create(VideoMode::getDesktopMode(), game_title, sf::Style::Fullscreen);
	}

	bool GameWindowManager::isGameRunning()
	{
		return game_Window->isOpen();
	}

	void GameWindowManager::render()
	{
		game_Window->clear(sf::Color(100, 50, 50, 255));

		game_Window->display();
	}

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_Window;
	}
}