#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "../Utility/TimeService.h"

using namespace sf;
using namespace std;

namespace Gameplay_N
{
	enum BallState
	{
		IDLE,
		MOVING
	};

	class Ball
	{
		private:
			Texture ball_texture;
			Sprite ball_sprite;
			string ball_texture_path = "Assets/Textures/Ball.png";
			BallState ballState = IDLE;

			const float ball_scale_x = 0.06f;
			const float ball_scale_y = 0.06f;
			const float ball_pos_x = 960.0f;
			const float ball_pos_y = 540.0f;
			const float center_pos_x = 960.0f;
			const float center_pos_y = 540.0f;

			//paddle orta tarafýna göre yukarý aþaðý düzeltilecek
			float ball_speed_x = 1000.0f;
			float ball_speed_y = 100.0f;
			Vector2f velocity = Vector2f(ball_speed_x, ball_speed_y);

			void loadTextures();
			void initializeVariables();
			void ball_move(Utility_N::TimeService *_time_service);
			void resetBall(FloatRect _ball_bounds, FloatRect _p1PaddleBounds, FloatRect _p2PaddleBounds, Utility_N::TimeService* _time_service, Paddle* _player1, Paddle* _player2);
			void checkIntersectWithBounds(FloatRect _ball_bounds);
			void checkIntersectWithPlayerBounds(FloatRect _ball_bounds, FloatRect _p1PaddleBounds, FloatRect _p2PaddleBounds);

		public:
			bool isCollisionContinue = false;

			Ball();
			void update(Paddle* _player1, Paddle* _player2, Utility_N::TimeService *_time_service); // for ball movement 
			void render(RenderWindow *_game_window); // for rendering ball on the window
			void handlePaddleCollision(Paddle* _player1, Paddle* _player2, Utility_N::TimeService* _time_service);
			void increaseBallSpeed();
	};
}