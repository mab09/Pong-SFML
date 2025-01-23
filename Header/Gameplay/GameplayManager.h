#pragma once
#include "Boundary/Boundary.h"
#include "Paddle/Paddle.h"
#include "Ball/Ball.h"
#include "../Event/EventManager.h"
#include "../Utility/TimeService.h"
#include "../UI/UIService.h"

using namespace Event;
using namespace Utility;
using namespace UI;

namespace Gameplay
{
	class GameplayManager {
	private:
		float player1_position_x = 100.0f;
		float player1_position_y = 700.0f;

		float player2_postion_x = 2500.0f;
		float player2_postion_y = 700.0f;

		Boundary* boundary;
		Ball* ball;
		Paddle* player1;
		Paddle* player2;

		EventManager* event_manager;
		TimeService* time_service;
		UIService* ui_service;

		void initialize();
		void UpdateScore();

	public:
		GameplayManager(EventManager* manager);
		void update();
		void render(RenderWindow* game_window);
	};
}