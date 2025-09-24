#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Event_N
{
	class EventManager
	{
		public:
			void PoolEvents(RenderWindow* _game_window); // Process all events
			bool isKeyPressedEM(sf::Keyboard::Key key); // Check spesific key
	};
}