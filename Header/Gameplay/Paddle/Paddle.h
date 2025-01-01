#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

namespace Gameplay
{
    class Paddle {
    private:
        Texture pong_paddle_texture;
        Sprite pong_paddle_sprite;

        const string texture_path = "Assets/Textures/Paddle.png";
        const float scale_x = 0.2f; // 20% of original size
        const float scale_y = 0.2f; // 20% of original size

        RectangleShape paddle_sprite;
        const float paddle_width = 20.0f;
        const float paddle_height = 140.0f;

        void loadTexture();
        void initializeVariables(float position_x, float position_y);

    public:
        Paddle(float position_x, float position_y);
        void update();
        void render(RenderWindow* game_window);
    };
}