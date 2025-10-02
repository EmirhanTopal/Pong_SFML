#include "../../Header/Gameplay/Paddle.h"
#include "../../Header/Gameplay/Boundary.h"
#include "../../Header/Event/Event.h"
#include "../../Header/Utility/TimeService.h"

using namespace Event_N;

namespace Gameplay_N
{
	Paddle::Paddle(float _pos_x, float _pos_y)
	{
		paddle_sprite.setSize(Vector2f(paddle_width, paddle_height));
		paddle_sprite.setPosition(_pos_x, _pos_y);
	}

	void Paddle::update(EventManager *_event_manager, sf::Keyboard::Key _upKey, sf::Keyboard::Key _downKey, Utility_N::TimeService* _time_service)
	{
		paddle_move(_event_manager, _upKey, _downKey, _time_service);
	}

	void Paddle::render(RenderWindow* _game_window)
	{
		_game_window->draw(paddle_sprite);
	}

	void Paddle::paddle_move(EventManager *_event_manager, sf::Keyboard::Key _upKey, sf::Keyboard::Key _downKey, Utility_N::TimeService *_time_service)
	{
		if (_event_manager->isKeyPressedEM(_upKey))
		{
			if (paddle_sprite.getGlobalBounds().top > 20)
			{
				if (velocity.y > 0)
					velocity.y *= -1;
				paddle_sprite.move(velocity * _time_service->getDeltaTime());
			}
		}
		else if (_event_manager->isKeyPressedEM(_downKey))
		{
			if ((paddle_sprite.getGlobalBounds().top + paddle_sprite.getGlobalBounds().height) < 1060)
			{
				if (velocity.y < 0)
					velocity.y *= -1;
				paddle_sprite.move(velocity * _time_service->getDeltaTime());
			}
		}
	}

	RectangleShape Paddle::getPaddleSprite()
	{
		return paddle_sprite;
	}

	void Paddle::increaaseScore()
	{
		player_score++;
	}

	int Paddle::getScore()
	{
		return player_score;
	}

	float Paddle::getPosX(int _p_value)
	{
		if (_p_value == 1)
			return player1_pos_x;
		else
			return player2_pos_x;
	}

	float Paddle::getPosY(int _p_value)
	{
		if (_p_value == 1)
			return player1_pos_y;
		else
			return player2_pos_y;
	}

	void Paddle::resetPos(int _p_value)
	{
		if (_p_value == 1)
			paddle_sprite.setPosition(player1_pos_x, player1_pos_y);
		else
			paddle_sprite.setPosition(player2_pos_x, player2_pos_y);
	}
}