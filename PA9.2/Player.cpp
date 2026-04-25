#include "Player.hpp"

Player::~Player()
{}

void Player::pointToMouse(const sf::Vector2i mousePosition)
{
    shape.rotate(sf::degrees(5));



}

void Player::playerMove()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        shape.move({0.f,float(0-moveSpeed)});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        shape.move({ float(0-moveSpeed),0.f });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        shape.move(sf::Vector2f{ 0.f,float(moveSpeed)});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        shape.move({ float( moveSpeed),0.f });
    }


}
