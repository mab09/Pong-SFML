#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

namespace Gameplay
{
    class Boundary {
	private:
		RectangleShape topBoundary;
		RectangleShape bottomBoundary;
		RectangleShape leftBoundary;
		RectangleShape rightBoundary;
		RectangleShape centerLine;

		const float horizontal_boundary_width = 2560.0f;
		const float horizontal_boundary_height = 20.0f;

		const float top_position_x = 0.0f;
		const float top_position_y = 0.0f;

		const float bottom_position_x = 0.0f;
		const float bottom_position_y = 1420.0f;

		const float vertical_boundary_width = 20.0f;
		const float vertical_boundary_height = 1440.0f;

		const float left_position_x = 0.0f;
		const float left_position_y = 0.0f;

		const float right_position_x = 2540.0f;
		const float right_position_y = 0.0f;

		const float center_line_width = 10.0f;
		const float center_line_height = 1400.0f;

		const float center_line_position_x = 1280.0f;
		const float center_line_position_y = 20.0f;

		const Color boundary_color = Color::Blue;
		const Color center_line_color = Color::White;

		void createTopBoundary();
		void createBottomBoundary();
		void createLeftBoundary();
		void createRightBoundary();

		void createCenterLine();

	public:
		Boundary();

		//void update();
		void render(RenderWindow* game_window);
    };
}