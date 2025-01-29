#include "../../Header/Gameplay/GameplayManager.h"

namespace Gameplay
{
	GameplayManager::GameplayManager(EventManager* manager) {
		time_service = new TimeService();
		time_service->initialize();// Start our time tracking

		ui_service = new UIService();
		
		event_manager = manager;
		boundary = new Boundary();
		initialize();
	}

	void GameplayManager::initialize() {
		ball = new Ball();
		player1 = new Paddle(player1_position_x, player1_position_y);
		player2 = new Paddle(player2_postion_x, player2_postion_y);
	}

	void GameplayManager::render(RenderWindow* game_window)	{
		boundary->render(game_window);
		ball->render(game_window);
		player1->render(game_window);
		player2->render(game_window);
		ui_service->render(game_window);
	}


	void GameplayManager::UpdateScore() {
		// Left side out - Player 2 scores!
		if (ball->isLeftCollisionOccurred()) {
			ui_service->incrementPlayer2Score();
			ball->updateLeftCollisionState(false);
		}

		// Right side out - Player 1 scores!
		if (ball->isRightCollisionOccurred()) {
			ui_service->incrementPlayer1Score();
			ball->updateRightCollisionState(false);
		}
	}

    void GameplayManager::update() {
		time_service->update();
		
		ball->update(player1, player2, time_service);

		player1->update(event_manager->isKeyPressed(Keyboard::W), event_manager->isKeyPressed(Keyboard::S), time_service);
		player2->update(event_manager->isKeyPressed(Keyboard::Up), event_manager->isKeyPressed(Keyboard::Down), time_service);

		UpdateScore();       // Check for scoring events
		ui_service->update(); // Update score display

    }
}