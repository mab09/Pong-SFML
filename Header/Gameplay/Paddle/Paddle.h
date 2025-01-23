#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "../../Utility/TimeService.h"

using namespace sf;
using namespace std;
using namespace Utility;

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

        const float paddleSpeed = 0.25f;

        const float top_boundary = 20.0f;
        const float bottom_boundary = 1380.0f;

        void loadTexture();
        void initializeVariables(float position_x, float position_y);

        void movePaddle(bool move_up_key_pressed, bool move_down_key_pressed, TimeService* time_service);

    public:
        Paddle(float position_x, float position_y);

        Sprite getPaddleSprite();

        void update(bool move_up_key_pressed, bool move_down_key_pressed, TimeService* time_service);
        void render(RenderWindow* game_window);
    };
}