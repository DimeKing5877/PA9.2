#include "Player.hpp"

Player::~Player()
{}

bool Player::vulnrable(){
    return isVulnrable;
}
void Player::setVulnrabile(const bool vulnrable){
    isVulnrable = vulnrable;
}


int Player::getWeaponSlot(){
    return weaponSlot;
}
void Player::setWeaponSlot(const int newWeaponSlot){
    weaponSlot = newWeaponSlot;
}
void Player::setWeaponSlot(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
        weaponSlot = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
        weaponSlot = 2;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) {
        weaponSlot = 3;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) {
        weaponSlot = 4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num5)) {
        weaponSlot = 5;
    }
}





void Player::pointToMouse(const sf::Vector2f mousePosition)
{
    sf::Vector2f direction = mousePosition - shape.getPosition();
    float angle = atan2(direction.y, direction.x);
    shape.setRotation(sf::radians(angle + (3.141/2)));
    rotateWeapons(sf::radians(angle + (3.141 / 2)));
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

    //update weapon position 
    setWeaponsPosition();
}



void Player::draw(sf::RenderWindow*& window){
   
    if (weaponSlot == 1) {
        mainWeapon.draw(window);
    }
    else if (weaponSlot == 2) {
        secondWeapon.draw(window);
    } 
    else if (weaponSlot == 3) {
        thirdWeapon.draw(window);
    }
    else if (weaponSlot == 4) {
    
    }
    else if (weaponSlot == 5) {

    }
    window->draw(this->shape);
}
void Player::setWeaponsPosition(){
    mainWeapon.setObjectPosition(shape.getPosition().x, shape.getPosition().y);
    secondWeapon.setObjectPosition(shape.getPosition().x, shape.getPosition().y);
    thirdWeapon.setObjectPosition(shape.getPosition().x, shape.getPosition().y);
}
void Player::setWeaponSize(){
    mainWeapon.getShape().scale({ 2.f,2.f });
    secondWeapon.getShape().scale({ 1.75,1.75 });
    thirdWeapon.getShape().scale({ 2.f,2.f });
}
void Player::rotateWeapons(sf::Angle rotation){

    mainWeapon.getShape().setRotation(rotation);
    secondWeapon.getShape().setRotation(rotation);
    thirdWeapon.getShape().setRotation(rotation);
}






void Player::shootGun(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        if (weaponSlot == 1) {
            std::cout << "cannon 1" << std::endl;
        }
        else if (weaponSlot == 2) {
            std::cout << "cannon 2" << std::endl;
        }
        else if (weaponSlot == 3) {
            std::cout << "cannon 3" << std::endl;
        }
        else if (weaponSlot == 4) {
            std::cout << "cannon 4" << std::endl;
        }
        else if (weaponSlot == 5) {
            std::cout << "cannon 5" << std::endl;
        }
    }
}










