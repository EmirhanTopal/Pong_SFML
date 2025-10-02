#include "../../Header/Gameplay/Ball.h"

namespace Gameplay_N
{
	Ball::Ball()
	{
		current_ball_speed_x = ball_speed_x;
		current_ball_speed_y = ball_speed_y;
		/*ball_sprite.setRadius(ball_radius);
		ball_sprite.setPosition(ball_pos_x, ball_pos_y);
		ball_sprite.setFillColor(Color::Blue);*/
		loadTextures();
		initializeVariables();
	}

	void Ball::update(Paddle* _player1, Paddle* _player2, Utility_N::TimeService* _time_service)
	{
		ball_move(_time_service);
		handlePaddleCollision(_player1, _player2, _time_service);
	}

	void Ball::render(RenderWindow *_game_window)
	{
		_game_window->draw(ball_sprite);
	}

	void Ball::loadTextures()
	{
		if (!ball_texture.loadFromFile(ball_texture_path))
		{
			throw std::runtime_error("Failed to laod ball texture!");
		}
	}

	void Ball::initializeVariables()
	{
		ball_sprite.setTexture(ball_texture);
		ball_sprite.setScale(ball_scale_x, ball_scale_y);
		ball_sprite.setPosition(ball_pos_x, ball_pos_y);
	}

	void Ball::ball_move(Utility_N::TimeService* _time_service)
	{
		if (_time_service->updateDelayTime(_time_service->getDeltaTime()))
		{
			ballState = MOVING;
			if (ballState == MOVING)
			{
				ball_sprite.move(velocity * _time_service->getDeltaTime());
			}
		}
	}

	void Ball::handlePaddleCollision(Paddle* _player1, Paddle* _player2, Utility_N::TimeService* _time_service)
	{
		// get sprites
		const RectangleShape& player1PaddleSprite = _player1->getPaddleSprite(); // reference type 
		const RectangleShape& player2PaddleSprite = _player2->getPaddleSprite(); // reference type

		// get boundries
		FloatRect player1PaddleBounds = player1PaddleSprite.getGlobalBounds();
		FloatRect player2PaddleBounds = player2PaddleSprite.getGlobalBounds();
		FloatRect ballBounds = ball_sprite.getGlobalBounds();

		// adjust inctersect situations
		checkIntersectWithPlayerBounds(ballBounds, player1PaddleBounds, player2PaddleBounds);
		checkIntersectWithBounds(ballBounds);
		resetBall(ballBounds, player1PaddleBounds, player2PaddleBounds, _time_service, _player1, _player2);
	}

	void Ball::checkIntersectWithPlayerBounds(FloatRect _ball_bounds, FloatRect _p1PaddleBounds, FloatRect _p2PaddleBounds)
	{
		float p1_center = _p1PaddleBounds.top + (_p1PaddleBounds.height / 2);
		float p2_center = _p2PaddleBounds.top + (_p2PaddleBounds.height / 2);
		float ball_center = _ball_bounds.top + (_ball_bounds.height / 2);
		if (_p1PaddleBounds.intersects(_ball_bounds))
		{
			if (!isCollisionContinue)
			{
				if (p1_center > ball_center)
				{
					if (velocity.y < 0)
						velocity.y *= -1;
				}
				else if (p1_center < ball_center)
				{
					if (velocity.y > 0)
						velocity.y *= -1;
				}
				velocity.x *= -1;
				increaseBallSpeed();
				isCollisionContinue = true;
			}
		}
		else if (_p2PaddleBounds.intersects(_ball_bounds))
		{
			if (!isCollisionContinue)
			{
				if (p2_center > ball_center)
				{
					if (velocity.y < 0)
						velocity.y *= -1;
				}
				else if (p2_center < ball_center)
				{
					if (velocity.y > 0)
						velocity.y *= -1;
				}
				velocity.x *= -1;
				increaseBallSpeed();
				isCollisionContinue = true;
			}
		}
		else
			isCollisionContinue = false;
	}

	void Ball::checkIntersectWithBounds(FloatRect _ball_bounds)
	{
		if (_ball_bounds.top <= 20 && velocity.y < 0)
			velocity.y *= -1;
		else if ((_ball_bounds.top + _ball_bounds.height) >= 1040 && velocity.y > 0)
			velocity.y *= -1;
	}

	void Ball::resetBall(FloatRect _ball_bounds, FloatRect _p1PaddleBounds, FloatRect _p2PaddleBounds, Utility_N::TimeService *_time_service, Paddle* _player1, Paddle* _player2)
	{
		if (_ball_bounds.left > (_p2PaddleBounds.left + _p2PaddleBounds.width))
		{
			_player1->increaaseScore();
			resetBallSpeed(2);
			isScored = true;
			
		}
		else if ((_ball_bounds.left + _ball_bounds.width) < _p1PaddleBounds.left)
		{
			_player2->increaaseScore();
			resetBallSpeed(1);
			isScored = true;
		}
		if (isScored)
		{
			_player1->resetPos(1);
			_player2->resetPos(2);
			
			ball_sprite.setPosition(center_pos_x, center_pos_y);
			ballState = IDLE;
			_time_service->elapsed_delay_time = 0;
			isScored = false;
		}
	}

	void Ball::increaseBallSpeed()
	{
		current_ball_speed_x += 100.0f;
		current_ball_speed_y += 20.0f;

		if (velocity.x < 0)
			velocity.x = -current_ball_speed_x;
		else
			velocity.x = current_ball_speed_x;

		if (velocity.y < 0)
			velocity.y = -current_ball_speed_y;
		else
			velocity.y = current_ball_speed_y;
	}

	void Ball::resetBallSpeed(int _p_value)
	{
		current_ball_speed_x = ball_speed_x;
		if (_p_value == 1)
			velocity.x = -current_ball_speed_x;
		else
			velocity.x = current_ball_speed_x;
		current_ball_speed_y = ball_speed_y;
		velocity.y = current_ball_speed_y;
	}
}