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

	RenderWindow* GameWindowManager::getGameWindow()
	{
		return game_Window;
	}

	void GameWindowManager::clearGameWindow()
	{
		game_Window->clear();
	}

	void GameWindowManager::displayGameWindow()
	{
		return game_Window->display();
	}
}