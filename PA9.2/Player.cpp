#include "Player.hpp"

Player::~Player()
{}

void Player::pointToMouse(const sf::Vector2f mousePosition)
{
    sf::Vector2f direction = mousePosition - shape.getPosition();
    float angle = atan2(direction.y, direction.x);
    shape.setRotation(sf::radians(angle + (3.141/2)));

}

void Player::playerMove()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && (this->shape.getPosition().y > 0))
    {
        shape.move({0.f,float(0-moveSpeed)});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && (this->shape.getPosition().x > 0))
    {
        shape.move({ float(0-moveSpeed),0.f });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && (this->shape.getPosition().y < WINDOW_LENGTH))
    {
        shape.move(sf::Vector2f{ 0.f,float(moveSpeed)});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && (this->shape.getPosition().x < WINDOW_WIDTH))
    {
        shape.move({ float( moveSpeed),0.f });
    }


}
