#pragma once
#include <SFML/Graphics.hpp>
#include "../Paddle/Paddle.h"
#include <string>

#include "../../Utility/TimeService.h"
#include "../../Sound/SoundManager.h"

using namespace sf;
using namespace std;
using namespace Utility;
using namespace Sound;

namespace Gameplay
{
    enum class BallState {
        Idle,
        Moving
    };

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

        float ball_speed = .05f;
        Vector2f velocity = Vector2f(ball_speed, ball_speed);

        const float top_boundary = 20.0f;
        const float bottom_boundary = 1420.0f;
        const float left_boundary = 0.0f;
        const float right_boundary = 2560.0f;

        //Center Position
        const float center_position_x = 1230.0f;
        const float center_position_y = 650.0f;

        float delay_duration = 3.0f;
        float elapsed_delay_time = 0.0f;

        bool had_left_collison = false;
        bool had_right_collison = false;

        void loadTexture();
        void initializeVariables();
        void move(TimeService* time_service);
        void onCollision(Paddle* player1, Paddle* player2);
        void handlePaddleCollision(Paddle* player1, Paddle* player2);
        void handleBoundaryCollision();
        void handleOutofBoundCollision();
        void reset();

        void updateDelayTime(float deltaTime);
        BallState current_state;

    public:
        Ball();
        void update(Paddle* player1, Paddle* player2, TimeService* time_service);
        void render(RenderWindow* game_window);

        bool isLeftCollisionOccurred();
        void updateLeftCollisionState(bool value);

        bool isRightCollisionOccurred();
        void updateRightCollisionState(bool value);
    };
}