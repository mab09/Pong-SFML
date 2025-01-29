#include "../../Header/Gameplay/Ball/Ball.h"

namespace Gameplay
{
    Ball::Ball() {
        ball_sprite.setRadius(radius);
        ball_sprite.setPosition(position_x, position_y);
        current_state = BallState::Idle;

        loadTexture();
        initializeVariables();
    }

    void Ball::render(RenderWindow* game_window) {
        //game_window->draw(ball_sprite);   //Ball as Circle Shape 
        game_window->draw(pong_ball_sprite); //Ball as Texture
    }

    void Ball::loadTexture() {
        if (!pong_ball_texture.loadFromFile(texture_path)) {
            throw std::runtime_error("Failed to load ball texture!");
        }
    }

    void Ball::initializeVariables() {
        pong_ball_sprite.setTexture(pong_ball_texture);  // Link texture to sprite
        pong_ball_sprite.setScale(scale_x, scale_y);     // Set size
        pong_ball_sprite.setPosition(position_x, position_y); // Set position
    }

    void Ball::move(Utility::TimeService* time_service) {
        updateDelayTime(time_service->getDeltaTime());

        int speedMultiplier = 10000;
        if (current_state == BallState::Idle) pong_ball_sprite.move(Vector2f(0,0));
        if (current_state == BallState::Moving) pong_ball_sprite.move(velocity * (time_service->getDeltaTime() * speedMultiplier));
    }

    void Ball::handlePaddleCollision(Paddle* player1, Paddle* player2) {
        // 1. Get our sprites
        const Sprite& player1Paddle = player1->getPaddleSprite();
        const Sprite& player2Paddle = player2->getPaddleSprite();

        // 2. Check their bounds
        FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();
        FloatRect player1_bounds = player1Paddle.getGlobalBounds();
        FloatRect player2_bounds = player2Paddle.getGlobalBounds();

        // 3. Handle collisions
        if (ball_bounds.intersects(player1_bounds) && velocity.x < 0) {
            velocity.x = -velocity.x;  // Bounce!
        }
        if (ball_bounds.intersects(player2_bounds) && velocity.x > 0) {
            velocity.x = -velocity.x;  // Reverse horizontal direction
        }
    }

    void Ball::handleBoundaryCollision() {
        FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

        if ((ball_bounds.top <= top_boundary && velocity.y < 0) || (ball_bounds.top + ball_bounds.height >= bottom_boundary && velocity.y > 0)) {
            velocity.y = -velocity.y;  // Reverse vertical direction
        }
    }

    void Ball::handleOutofBoundCollision() {
        FloatRect ball_bounds = pong_ball_sprite.getGlobalBounds();

        if (ball_bounds.left <= left_boundary) {
            updateLeftCollisionState(true);
            reset();        // Player 2 scores!
        }
        else if (ball_bounds.left + ball_bounds.width >= right_boundary) {
            updateRightCollisionState(true);
            reset();        // Player 1 scores!
        }
    }

    void Ball::onCollision(Paddle* player1, Paddle* player2) {
        handleBoundaryCollision();
        handlePaddleCollision(player1, player2);
        handleOutofBoundCollision();
    }

    bool Ball::isLeftCollisionOccurred() {
        return had_left_collison;
    }

    void Ball::updateLeftCollisionState(bool value) {
        had_left_collison = value;
    }

    bool Ball::isRightCollisionOccurred() {
        return had_right_collison;
    }

    void Ball::updateRightCollisionState(bool value) {
        had_right_collison = value;
    }

    void Ball::reset() {
        pong_ball_sprite.setPosition(center_position_x, center_position_y);
        velocity = Vector2f(ball_speed, ball_speed);
    }

    void Ball::updateDelayTime(float deltaTime) {
        if (current_state == BallState::Idle) {
            elapsed_delay_time += deltaTime;
            if (elapsed_delay_time >= delay_duration) {
                current_state = BallState::Moving;
            }
            else {
                return;
            }
        }
    }

    void Ball::update(Paddle* player1, Paddle* player2, Utility::TimeService* time_service) {
        move(time_service);
        onCollision(player1, player2);
    }

}