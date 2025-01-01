#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

namespace Gameplay
{
    class Ball {
    private:
        Texture pong_ball_texture;
        Sprite pong_ball_sprite;

        const string texture_path = "Assets/Textures/Ball.png";
        const float scale_x = 0.02f; // 20% of original size
        const float scale_y = 0.02f; // 20% of original size

        CircleShape ball_sprite;
        const float radius = 10.0f;
        const float position_x = 1280.0f;
        const float position_y = 720.0f;

        float ball_speed = .5f;
        Vector2f velocity = Vector2f(ball_speed, ball_speed);


        void loadTexture();
        void initializeVariables();
        void move();

    public:
        Ball();
        void update();
        void render(RenderWindow* game_window);
    };
}