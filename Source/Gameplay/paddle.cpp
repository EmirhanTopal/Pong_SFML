#include "../../Header/Gameplay/Paddle.h"
#include "../../Header/Event/Event.h"

using namespace Event_N;

namespace Gameplay_N
{
	Paddle::Paddle(float _pos_x, float _pos_y)
	{
		paddle_sprite.setSize(Vector2f(paddle_width, paddle_height));
		paddle_sprite.setPosition(_pos_x, _pos_y);
	}

	void Paddle::update(EventManager *_event_manager, int player_num)
	{
		Paddle::paddle_move(_event_manager, player_num);
	}

	void Paddle::render(RenderWindow* _game_window)
	{
		_game_window->draw(paddle_sprite);
	}

	void Paddle::paddle_move(EventManager *_event_manager, int player_num)
	{
		if (player_num == 1)
		{
			if (_event_manager->isKeyPressedEM(sf::Keyboard::Up))
			{
				if (velocity.y > 0)
				{
					velocity.y *= -1;
				}
				paddle_sprite.move(velocity);
			}
			else if (_event_manager->isKeyPressedEM(sf::Keyboard::Down))
			{
				if (velocity.y < 0)
					velocity.y *= -1;
				paddle_sprite.move(velocity);
			}
		}
		if (player_num == 2)
		{
			if (_event_manager->isKeyPressedEM(sf::Keyboard::W))
			{
				if (velocity.y > 0)
				{
					velocity.y *= -1;
				}
				paddle_sprite.move(velocity);
			}
			else if (_event_manager->isKeyPressedEM(sf::Keyboard::S))
			{
				if (velocity.y < 0)
					velocity.y *= -1;
				paddle_sprite.move(velocity);
			}
		}
	}
}