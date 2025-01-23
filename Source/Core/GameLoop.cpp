#include "../../Header/Core/GameLoop.h"

namespace Core
{
    void GameLoop::initialize() {
        game_window_manager = new GameWindowManager();
        event_manager = new EventManager();
        gameplay_manager = new GameplayManager(event_manager);

        game_window_manager->initialize();
    }

    bool GameLoop::isGameRunning() {
        return game_window_manager->isGameRunning();
    }

    void GameLoop::pollEvent() {
        event_manager->pollEvents(game_window_manager->getGameWindow());
    }

    void GameLoop::update() {

        gameplay_manager->update();

    }

    void GameLoop::render() {
        game_window_manager->clearGameWindow();

        //render the paddles and ball
        gameplay_manager->render(game_window_manager->getGameWindow());

        game_window_manager->displayGameWindow();
    }

}