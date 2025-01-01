#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace Core {
    class GameWindowManager {
    private:
        int game_window_width = 1280;
        int game_window_height = 720;
        std::string game_title = "SFML-Pong!";

        RenderWindow* game_window;

        void createGameWindow();

    public:
        void initialize();
        RenderWindow* getGameWindow();
        bool isGameRunning();
        void clearGameWindow();
        void displayGameWindow();
    };
}