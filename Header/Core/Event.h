#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

namespace Event_N
{
	class EventManager
	{
		public:
			void PoolEvents(RenderWindow* _game_window); // Process all events
			bool isKeyPressedEM(sf::Keyboard::Key key); // Check spesific key
			bool isLeftMouseButtonClicked();
	};
}