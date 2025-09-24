#include "../../Header/Core/Event.h"

namespace Event_N
{
	void EventManager::PoolEvents(sf::RenderWindow *_game_Window)
	{
		sf::Event _event;
		while (_game_Window->pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
			{
				_game_Window->close();
				
			}
			if (isKeyPressedEM(sf::Keyboard::Escape))
			{
				_game_Window->close();
			}
		}
	}

	bool EventManager::isKeyPressedEM(sf::Keyboard::Key key)
	{
		return sf::Keyboard::isKeyPressed(key);
	}
}