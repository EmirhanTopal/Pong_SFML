#include "../../Header/Gameplay/Ball.h"

namespace Gameplay_N
{
	Ball::Ball()
	{
		/*ball_sprite.setRadius(ball_radius);
		ball_sprite.setPosition(ball_pos_x, ball_pos_y);
		ball_sprite.setFillColor(Color::Blue);*/
		loadTextures();
		initializeVariables();
	}

	void Ball::update(Paddle* _player1, Paddle* _player2)
	{
		ball_move();
		handlePaddleCollision(_player1, _player2);
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

	void Ball::ball_move()
	{
		ball_sprite.move(velocity);
	}

	void Ball::handlePaddleCollision(Paddle* _player1, Paddle* _player2)
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
		resetBall(ballBounds, player1PaddleBounds, player2PaddleBounds);
	}

	void Ball::checkIntersectWithPlayerBounds(FloatRect _ball_bounds, FloatRect _p1PaddleBounds, FloatRect _p2PaddleBounds)
	{
		if (_p1PaddleBounds.intersects(_ball_bounds))
			velocity.x *= -1;
		else if (_p2PaddleBounds.intersects(_ball_bounds))
			velocity.x *= -1;
	}

	void Ball::checkIntersectWithBounds(FloatRect _ball_bounds)
	{
		if (_ball_bounds.top <= 20 && velocity.y < 0)
			velocity.y *= -1;
		else if ((_ball_bounds.top + _ball_bounds.height) >= 1040 && velocity.y > 0)
			velocity.y *= -1;
	}

	void Ball::resetBall(FloatRect _ball_bounds, FloatRect _p1PaddleBounds, FloatRect _p2PaddleBounds)
	{
		if (((_ball_bounds.left + _ball_bounds.width) < _p1PaddleBounds.left)
			|| _ball_bounds.left > (_p2PaddleBounds.left + _p2PaddleBounds.width))
		{
			ball_sprite.setPosition(center_pos_x, center_pos_y);
		}
	}

}