#include "../../Header/Gameplay/Ball/Ball.h"

namespace Gameplay
{
    Ball::Ball() {
        ball_sprite.setRadius(radius);
        ball_sprite.setPosition(position_x, position_y);

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

    void Ball::move() {
        pong_ball_sprite.move(velocity);
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
            reset();        // Player 2 scores!
        }
        else if (ball_bounds.left + ball_bounds.width >= right_boundary) {
            reset();        // Player 1 scores!
        }
    }

    void Ball::onCollision(Paddle* player1, Paddle* player2) {
        handleBoundaryCollision();
        handlePaddleCollision(player1, player2);
        handleOutofBoundCollision();
    }

    void Ball::reset() {
        pong_ball_sprite.setPosition(center_position_x, center_position_y);
        velocity = Vector2f(ball_speed, ball_speed);
    }

    void Ball::update(Paddle* player1, Paddle* player2) {
        move();
        onCollision(player1, player2);
    }

}