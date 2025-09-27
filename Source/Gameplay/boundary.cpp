#include "../../Header/Gameplay/Boundary.h"

namespace Gameplay_N
{
	Boundary::Boundary()
	{
		setTopBoundaryPos();
		setBottomBoundaryPos();
		setLeftBoundaryPos();
		setRightBoundaryPos();
		setCenterBoundaryPos();
	}

	void Boundary::render(RenderWindow* _game_window)
	{
		_game_window->draw(leftBoundary);
		_game_window->draw(rightBoundary);
		_game_window->draw(topBoundary);
		_game_window->draw(bottomBoundary);
		_game_window->draw(centerLine);
	}

	void Boundary::setTopBoundaryPos()
	{
		topBoundary.setSize(Vector2f(horizontal_boundary_width, horizontal_boundary_height));
		topBoundary.setPosition(top_pos_x, top_pos_y);
		topBoundary.setFillColor(Color::Red);
	}

	void Boundary::setBottomBoundaryPos()
	{
		bottomBoundary.setSize(Vector2f(horizontal_boundary_width, horizontal_boundary_height));
		bottomBoundary.setPosition(bottom_pos_x, bottom_pos_y);
		bottomBoundary.setFillColor(Color::Red);
	}

	void Boundary::setLeftBoundaryPos()
	{
		leftBoundary.setSize(Vector2f(vertical_boundary_width, vertical_boundary_height));
		leftBoundary.setPosition(left_pos_x, left_pos_y);
		leftBoundary.setFillColor(Color::Red);
	}

	void Boundary::setRightBoundaryPos()
	{
		rightBoundary.setSize(Vector2f(vertical_boundary_width, vertical_boundary_height));
		rightBoundary.setPosition(right_pos_x, right_pos_y);
		rightBoundary.setFillColor(Color::Red);
	}

	void Boundary::setCenterBoundaryPos()
	{
		centerLine.setSize(Vector2f(vertical_boundary_width, vertical_boundary_height));
		centerLine.setPosition(center_pos_x, center_pos_y);
		centerLine.setFillColor(Color::White);
	}
}