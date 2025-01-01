#include "Header/Core/GameWindowManager.h"
#include "Header/Event/EventManager.h"

using namespace sf;
using namespace Core;
using namespace Event;

int main() {
    // Create our window manager instance
    GameWindowManager gameWindowManager;
    //Create an object of event manager
    EventManager eventManager;

    // Initialize the window
    gameWindowManager.initialize();

    while (gameWindowManager.isGameRunning()) {
        eventManager.pollEvents(gameWindowManager.getGameWindow());
        gameWindowManager.render();
    }

    return 0;
}