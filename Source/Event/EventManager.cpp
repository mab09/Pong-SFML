#include "../../Header/Event/EventManager.h"

namespace Event
{
    void EventManager::pollEvents(RenderWindow* game_window) {
        sf::Event event;
        while (game_window->pollEvent(event)) {
            // Handle window close event
            if (event.type == sf::Event::Closed) {
                game_window->close();
            }

            // Check for Escape key
            if (isKeyPressed(sf::Keyboard::Escape)) {
                game_window->close();
            }
        }
    }

    bool EventManager::isKeyPressed(sf::Keyboard::Key key) {
        // Detect if a specific key is pressed
        return sf::Keyboard::isKeyPressed(key);
    }

}