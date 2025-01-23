#include "../../Header/Gameplay/Paddle/Paddle.h"

namespace Gameplay
{
    Paddle::Paddle(float position_x, float position_y) {
        paddle_sprite.setSize(Vector2f(paddle_width, paddle_height));
        paddle_sprite.setPosition(position_x, position_y);

        loadTexture();
        initializeVariables(position_x, position_y);
    }

    void Paddle::render(RenderWindow* game_window) {
        //game_window->draw(paddle_sprite);   //Paddle as Rect Shape 
        game_window->draw(pong_paddle_sprite); //Ball as Texture
    }

    void Paddle::loadTexture() {
        if (!pong_paddle_texture.loadFromFile(texture_path)) {
            throw std::runtime_error("Failed to load ball texture!");
        }
    }

    void Paddle::initializeVariables(float position_x, float position_y) {
        pong_paddle_sprite.setTexture(pong_paddle_texture);  // Link texture to sprite
        pong_paddle_sprite.setScale(scale_x, scale_y);     // Set size
        pong_paddle_sprite.setPosition(position_x, position_y); // Set position
        pong_paddle_sprite.setRotation(90); //Make them verticle
    }

    void Paddle::movePaddle(bool move_up_key_pressed, bool move_down_key_pressed, Utility::TimeService* time_service) {

        int speedMultiplier = 5000;

        //move up
        if (move_up_key_pressed && pong_paddle_sprite.getPosition().y > top_boundary) {
            pong_paddle_sprite.move(0, -paddleSpeed * time_service->getDeltaTime() * speedMultiplier);
        }
        //move down
        if (move_down_key_pressed && pong_paddle_sprite.getPosition().y + paddle_sprite.getSize().y < bottom_boundary) {
            pong_paddle_sprite.move(0, paddleSpeed * time_service->getDeltaTime() * speedMultiplier);
        }
    }

    Sprite Paddle::getPaddleSprite() {
        return pong_paddle_sprite;
    }

    void Paddle::update(bool move_up_key_pressed, bool move_down_key_pressed, Utility::TimeService* time_service) {

        movePaddle(move_up_key_pressed, move_down_key_pressed, time_service);

    }

}