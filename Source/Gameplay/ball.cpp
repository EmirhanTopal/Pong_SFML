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

	void Ball::update()
	{
		Ball::ball_move();
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
}