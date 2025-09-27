#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace Gameplay_N
{
	class Ball
	{
		private:
			/*CircleShape ball_sprite;
			const float ball_radius = 10.0f;
			const float ball_pos_x = 500.0f;
			const float ball_pos_y = 500.0f;*/
			Texture ball_texture;
			Sprite ball_sprite;
			string ball_texture_path = "Assets/Textures/Ball.png";

			const float ball_scale_x = 0.06f;
			const float ball_scale_y = 0.06f;
			const float ball_pos_x = 615.0f;
			const float ball_pos_y = 325.0f;

			float ball_speed = 0.01f;
			Vector2f velocity = Vector2f(ball_speed, ball_speed);

			void loadTextures();
			void initializeVariables();
			void ball_move();
		public:
			Ball();
			void update(); // for ball movement 
			void render(RenderWindow *_game_window); // for rendering ball on the window

	};
}