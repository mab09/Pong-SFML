#include "../../Header/Event/EventManager.h"
#include <iostream>

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

            // Handle left mouse button click
            if (isLeftMouseButtonClicked())
            {
                sf::Vector2i position = sf::Mouse::getPosition(*game_window);

                // Log the mouse position
                std::cout << "Left mouse click at: " << position.x << ", " << position.y << std::endl;
            }
        }
    }

    bool EventManager::isLeftMouseButtonClicked() {
        // Detect if the left mouse button is clicked
        return (sf::Mouse::isButtonPressed(sf::Mouse::Left));
    }

    bool EventManager::isKeyPressed(sf::Keyboard::Key key) {
        // Detect if a specific key is pressed
        return sf::Keyboard::isKeyPressed(key);
    }

}