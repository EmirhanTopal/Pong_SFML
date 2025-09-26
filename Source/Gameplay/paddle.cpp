#include "../../Header/Gameplay/Paddle.h"

namespace Gameplay_N
{
	Paddle::Paddle(float _pos_x, float _pos_y)
	{
		paddle_sprite.setSize(Vector2f(paddle_width, paddle_height));
		paddle_sprite.setPosition(_pos_x, _pos_y);
	}

	void Paddle::update()
	{
	
	}

	void Paddle::render(RenderWindow* _game_window)
	{
		_game_window->draw(paddle_sprite);
	}
}