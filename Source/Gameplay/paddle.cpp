#include "../../Header/Gameplay/Paddle.h"
#include "../../Header/Gameplay/Boundary.h"
#include "../../Header/Event/Event.h"

using namespace Event_N;

namespace Gameplay_N
{
	Paddle::Paddle(float _pos_x, float _pos_y)
	{
		paddle_sprite.setSize(Vector2f(paddle_width, paddle_height));
		paddle_sprite.setPosition(_pos_x, _pos_y);
	}

	void Paddle::update(EventManager *_event_manager, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey)
	{
		paddle_move(_event_manager, upKey, downKey);
	}

	void Paddle::render(RenderWindow* _game_window)
	{
		_game_window->draw(paddle_sprite);
	}

	void Paddle::paddle_move(EventManager *_event_manager, sf::Keyboard::Key upKey, sf::Keyboard::Key downKey)
	{
		if (_event_manager->isKeyPressedEM(upKey))
		{
			if (paddle_sprite.getGlobalBounds().top > 20)
			{
				if (velocity.y > 0)
					velocity.y *= -1;
				paddle_sprite.move(velocity);
			}
		}
		else if (_event_manager->isKeyPressedEM(downKey))
		{
			if ((paddle_sprite.getGlobalBounds().top + paddle_sprite.getGlobalBounds().height) < 1060)
			{
				if (velocity.y < 0)
					velocity.y *= -1;
				paddle_sprite.move(velocity);
			}
		}
	}

	RectangleShape Paddle::getPaddleSprite()
	{
		return paddle_sprite;
	}
}