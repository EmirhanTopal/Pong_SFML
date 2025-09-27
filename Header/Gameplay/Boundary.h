#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace Gameplay_N
{
	class Boundary
	{
		private:
			RectangleShape leftBoundary;
			RectangleShape rightBoundary;
			RectangleShape topBoundary;
			RectangleShape bottomBoundary;
			RectangleShape centerLine;

			const float horizontal_boundary_width = 1920.0f;
			const float horizontal_boundary_height = 20.0f;

			const float vertical_boundary_width = 20.0f;
			const float vertical_boundary_height = 1080.0f;

			const float top_pos_x = 0.0f;
			const float top_pos_y = 0.0f;

			const float bottom_pos_x = 0.0f;
			const float bottom_pos_y = 1060.0f;

			const float left_pos_x = 0.0f;
			const float left_pos_y = 0.0f;

			const float right_pos_x = 1900.0f;
			const float right_pos_y = 0.0f;

			const float center_pos_x = 960.0f;
			const float center_pos_y = 0.0f;

			void setTopBoundaryPos();
			void setBottomBoundaryPos();
			void setLeftBoundaryPos();
			void setRightBoundaryPos();
			void setCenterBoundaryPos();

		public:
			Boundary();
			void render(RenderWindow *_game_window);
	};
}