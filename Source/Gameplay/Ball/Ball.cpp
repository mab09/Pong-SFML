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
        if (!pong_ball_texture.loadFromFile(texture_path))
        {
            throw std::runtime_error("Failed to load ball texture!");
        }
    }

    void Ball::initializeVariables() {
        pong_ball_sprite.setTexture(pong_ball_texture);  // Link texture to sprite
        pong_ball_sprite.setScale(scale_x, scale_y);     // Set size
        pong_ball_sprite.setPosition(position_x, position_y); // Set position
    }

    void Ball::update() {

    }

}