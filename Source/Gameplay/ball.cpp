#include "../../Header/Gameplay/Ball.h"

namespace Gameplay_N
{
	Ball::Ball()
	{
		ball_sprite.setRadius(ball_radius);
		ball_sprite.setPosition(ball_pos_x, ball_pos_y);
		ball_sprite.setFillColor(Color::Blue);
	}

	void Ball::update()
	{

	}

	void Ball::render(RenderWindow *_game_window)
	{
		_game_window->draw(ball_sprite);
	}
}