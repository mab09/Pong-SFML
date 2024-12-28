#include "Header/Core/GameWindowManager.h"

using namespace sf;
using namespace Core;

int main() {
    // Create our window manager instance
    GameWindowManager gameWindowManager;

    // Initialize the window
    gameWindowManager.initialize();

    while (gameWindowManager.isGameRunning()) {
        gameWindowManager.render();
    }

    return 0;
}